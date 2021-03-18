#include<iostream>
#include<cstring>
using namespace std;

const int N = 10010, M = 2 * N;

int d1[N], d2[N], p1[N], p2[N], up[N];
int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs_d(int u, int father)
{
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;
        int dis = dfs_d(j, u) + w[i];
        if(dis > d1[u]) 
        {
            d2[u] = d1[u], p2[u] = p1[u];
            d1[u] = dis, p1[u] = j;
        }
        else if(dis > d2[u]) 
        {
            d2[u] = dis, p2[u] = j;
        }
    }
    return d1[u];
}

void dfs_u(int u, int father)
{
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;
        if(p1[u] == j) up[j] = max(up[u], d2[u]) + w[i];
        else up[j] = max(d1[u], up[u]) + w[i];
        
        dfs_u(j, u);
    }
}

int main()
{
    int n; scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    dfs_d(1, -1);
    dfs_u(1, -1);
    
    int ans = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++) ans = min(ans, max(d1[i], up[i]));
    
    printf("%d\n", ans);
    
    return 0;
}
