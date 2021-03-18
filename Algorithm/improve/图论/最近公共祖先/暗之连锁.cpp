#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010, M = 300010;

int h[N], e[M], ne[M], idx;
int d[N];
int q[N];
int depth[N], fa[N][17];
int n, m;
int ans;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
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
                for(int k = 1; k <= 16; k++)
                {
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b)
{
    if(depth[a] < depth[b]) swap(a, b);
    for(int k = 16; k >= 0; k--)
    {
        if(depth[fa[a][k]] >= depth[b])
        {
            a = fa[a][k];
        }
    }
    if(a == b) return a;
    for(int k = 16; k >= 0; k--)
    {
        if(fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int dfs(int u, int father)
{
    int res = d[u];
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;
        
        int t = dfs(j, u);
        
        if(t == 0) ans += m;
        else if(t == 1) ans ++;
        res += t;
    }
    
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    bfs();
    
    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        d[a]++, d[b]++, d[lca(a, b)] -= 2;
    }
    
    dfs(1, -1);
    
    printf("%d\n", ans);
    
    return 0;
}
