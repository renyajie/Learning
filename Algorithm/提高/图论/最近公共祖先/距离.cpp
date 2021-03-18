include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 10010, M = 2 * N;

int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int q[N], depth[N], fa[N][15];
int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx]= c, ne[idx] = h[a], h[a] = idx++;
}

void bfs()
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    int hh = 0, tt = -1;
    q[++tt] = 1;
    
    while(hh <= tt)
    {
        int t = q[hh++];
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q[++tt] = j;
                fa[j][0] = t;
                
                for(int k = 1; k <= 14; k++)
                {
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
                }
            }
        }
    }
}

void dfs(int u, int father)
{
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;
        dist[j] = dist[u] + w[i];
        dfs(j, u);
    }
}

int lca(int a, int b)
{
    if(depth[a] < depth[b]) swap(a, b);
    for(int k = 14; k >= 0; k--)
    {
        if(depth[fa[a][k]] >= depth[b])
        {
            a = fa[a][k];
        }
    }
    if(a == b) return a;
    for(int k = 14; k >= 0; k--)
    {
        if(fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    bfs();
    
    dfs(1, -1);
    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        int p = lca(a, b);
        printf("%d\n", dist[a] + dist[b] - 2 * dist[p]);
    }
    
    return 0;
}
