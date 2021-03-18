#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 30, M = 6 * N + 10;

int h[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N];
int q[N];
bool st[N];
int num[N];
int r[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void build(int i)
{
    memset(h, -1, sizeof h);
    idx = 0;
    
    add(24, 0, -i);
    add(0, 24, i);
    
    for(int j = 1; j <= 24; j++)
    {
        add(j - 1, j, 0);
        add(j, j - 1, -num[j]);
    }
    
    for(int j = 8; j <= 24; j++)
    {
        add(j - 8, j, r[j]);
    }
    
    for(int j = 1; j <= 7; j++)
    {
        add(16 + j, j, r[j] - i);
    }
    
    for(int j = 1; j <= 24; j++)
    {
        add(0, j, 0);
    }
}

bool spfa()
{
    memset(dist, -0x3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    
    int hh = 0, tt = 0;
    q[tt++] = 0;
    dist[0] = 0;
    st[0] = true;
    
    while(hh != tt)
    {
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] < dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= 25) return false;
                
                if(!st[j])
                {
                    q[tt++] = j;
                    if(tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    
    return true;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        for(int i = 1; i <= 24; i++) scanf("%d", &r[i]);
        
        memset(num, 0, sizeof num);
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int t; scanf("%d", &t);
            num[t + 1] ++;
        }
        
        bool flag = true;
        for(int i = 0; i <= 1000; i++)
        {
            build(i);
            
            if(spfa()) 
            {
                printf("%d\n", i);
                flag = false;
                break;
            }
        }
        
        if(flag) puts("No Solution");
    }
    
    return 0;
}
