#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 10010, M = 30010;

int h[N], e[M], ne[M], w[M], idx;
int q[N], d[N];
int dist[N];
int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    int cnt = 1;
    int hh = 0, tt = -1;
    q[++tt] = 0;
    
    while(hh <= tt)
    {
        int t = q[hh++];
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(--d[j] == 0)
            {
                q[++tt] = j;
                cnt++;
            }
        }
    }
    
    return cnt == n + 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++) 
    {
        add(0, i, 100);
        d[i]++;
    }
    
    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        add(b, a, 1);
        d[a]++;
    }
    
    if(!topsort()) printf("Poor Xed\n");
    else
    {
        for(int i = 0; i <= n; i++)
        {
            int k = q[i];
            for(int j = h[k]; ~j; j = ne[j])
            {
                int u = e[j];
                dist[u] = max(dist[u], dist[k] + w[j]);
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans += dist[i];
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
