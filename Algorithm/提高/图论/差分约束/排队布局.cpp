#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1010, M = 41010;

int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
int q[N];
bool st[N];
int n, m1, m2;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(int sz)
{
    memset(dist, 0x3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    
    int hh = 0, tt = 0;
    for (int i = 1; i <= sz; i ++ )
    {
        q[tt ++ ] = i;
        dist[i] = 0;
        st[i] = true;
    }
    
    while(hh != tt)
    {
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return false;
                
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
    scanf("%d%d%d", &n, &m1, &m2);
    
    memset(h, -1, sizeof h);
    for(int i = 2; i <= n; i++) 
    {
        add(i, i - 1, 0);
        add(i, 1, 0); // 本题直接把1作为源点
    }
    
    for(int i = 0; i < m1; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        if(b < a) swap(a, b);
        add(a, b, c);
    }
    
    for(int i = 0; i < m2; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        if(b < a) swap(a, b);
        add(b, a, -c);
    }
    
    if(!spfa(n)) puts("-1"); // 做两边spfa，因为第一次负环不一定和1相通
    else
    {
        spfa(1); // 确定相通之后再做一遍
        if(dist[n] == 0x3f3f3f3f) puts("-2");
        else printf("%d\n", dist[n]);
    }
    
    return 0;
}
