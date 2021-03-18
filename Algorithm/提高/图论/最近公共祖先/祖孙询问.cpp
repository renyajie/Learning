#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 40010, M = 2 * N;

int h[N], e[M], ne[M], idx;
int depth[N], fa[N][17];
int q[N];
int n, m;
int root;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs()
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    int hh = 0, tt = -1;
    q[++tt] = root;
    
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
                for(int k = 1; k <= 16; k++) // 构造倍增数组从小到大构建
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

int main()
{
    scanf("%d", &n);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < n; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        if(b == -1) root = a;
        else add(a, b), add(b, a);
    }
    
    bfs();
    
    scanf("%d", &m);
    
    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        int p = lca(a, b);
        
        if(p == a) puts("1");
        else if(p == b) puts("2");
        else puts("0");
    }
    
    return 0;
}
