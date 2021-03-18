#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 50010, M = 3 * N + 10;

int h[N], e[M], ne[M], w[M], idx;
int dist[N]; //cnt[N];
bool st[N];
int q[N];
int n;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa()
{
    memset(dist, -0x3f, sizeof dist);
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
                //cnt[j] = cnt[t] + 1;
                //if(cnt[j] >= 50001) return false;
                
                if(!st[j])
                {
                    q[tt++] = j;
                    if(tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    
    //return true;
}

int main()
{
    scanf("%d", &n);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < n; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        a++, b++;
        add(a - 1, b, c);
    }
    
    for(int i = 1; i < N; i++)
    {
        add(i - 1, i, 0);
        add(i, i - 1, -1);
    }
    
    spfa();
    
    printf("%d\n", dist[50001]);
    
    return 0;
}
