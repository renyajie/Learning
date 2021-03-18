#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;

int g[N][N];
int p[N], l[N];
int m, n;
int dist[N];
bool st[N];

int dijkstra(int lb, int ub)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0] = 0;
    
    for(int i = 0; i < n; i++) // 包括0号点有N+1个点，更新N次
    {
        int t = -1;
        for(int j = 0; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
            {
                t = j;
            }
        }
        
        st[t] = true;
        for(int j = 0; j <= n; j++)
        {
            if(l[j] >= lb && l[j] <= ub)
            {
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
    }
    
    return dist[1];
}

int main()
{
    scanf("%d%d", &m, &n);
    
    memset(g, 0x3f, sizeof g);
    
    for(int i = 1; i <= n; i++)
    {
        int cnt; scanf("%d%d%d", &p[i], &l[i], &cnt);
        g[0][i] = min(g[0][i], p[i]);
        while(cnt--)
        {
            int b, c; scanf("%d%d", &b, &c);
            g[b][i] = min(g[b][i], c);
        }
    }
    
    int ans = 0x3f3f3f3f;
    for(int i = l[1] - m; i <= l[1]; i++)
    {
        ans = min(ans, dijkstra(i, i + m));
    }
    printf("%d\n", ans);
    
    return 0;
}

