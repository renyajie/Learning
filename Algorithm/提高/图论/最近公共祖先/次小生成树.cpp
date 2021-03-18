#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010, M = 3 * N, INF = 0x3f3f3f3f;

typedef long long ll;

struct Edge
{
    int a, b, w;
    bool f;
    bool operator< (const Edge &W) const
    {
        return w < W.w;
    }
}edges[M];

int h[N], e[M], ne[M], w[M], idx;
int depth[N], fa[N][19];
int d1[N][19], d2[N][19];
int q[N];
int p[N];
int n, m;
int dist[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
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
                d1[j][0] = w[i], d2[j][0] = -INF;
                for(int k = 1; k <= 18; k++)
                {
                    int mid = fa[j][k - 1];
                    fa[j][k] = fa[mid][k - 1];
                    
                    dist[0] = d1[mid][k - 1];
                    dist[1] = d2[mid][k - 1];
                    dist[2] = d1[j][k - 1];
                    dist[3] = d2[j][k - 1];
                    sort(dist, dist + 4);
                    
                    d1[j][k] = d2[j][k] = -INF;
                    for(int u = 0; u < 4; u++)
                    {
                        int d = dist[u];
                        if(d > d1[j][k]) d2[j][k] = d1[j][k], d1[j][k] = d;
                        else if(d != d1[j][k] && d > d2[j][k]) d2[j][k] = d;
                    }
                }
            }
        }
    }
}

int lca(int a, int b, int x)
{
    int cnt = 0;
    if(depth[a] < depth[b]) swap(a, b);
    for(int k = 18; k >= 0; k--)
    {
        if(depth[fa[a][k]] >= depth[b])
        {
            dist[cnt++] = d1[a][k];
            dist[cnt++] = d2[a][k];
            a = fa[a][k];
        }
    }
    if(a != b)
    {
        for(int k = 18; k >= 0; k--)
        {
            if(fa[a][k] != fa[b][k])
            {
                dist[cnt++] = d1[a][k];
                dist[cnt++] = d2[a][k];
                dist[cnt++] = d1[b][k];
                dist[cnt++] = d2[b][k];
                a = fa[a][k];
                b = fa[b][k];
            }
        }
        dist[cnt++] = d1[a][0];
        dist[cnt++] = d2[a][0];
    }
    
    int dist1 = -INF, dist2 = -INF;
    for(int i = 0; i < cnt; i++)
    {
        int d = dist[i];
        if(d > dist1) dist2 = dist1, dist1 = d;
        else if(d != dist1 && d > dist2) dist2 = d;
    }
    
    if(x > dist1) return x - dist1;
    if(x > dist2) return x - dist2;
    return INF;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }
    
    sort(edges, edges + m);
    for(int i = 1; i <= n; i++) p[i] = i;
    
    ll sum = 0;
    for(int i = 0; i < m; i++)
    {
        int a = find(edges[i].a), b = find(edges[i].b), w = edges[i].w;
        if(a != b)
        {
            p[a] = b;
            sum += w;
            edges[i].f = true;
        }
    }
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        if(!edges[i].f) continue;
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        add(a, b, w), add(b, a, w);
    }
    
    bfs();
    
    ll res = 1e18;
    for(int i = 0; i < m; i++)
    {
        if(edges[i].f) continue;
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        res = min(res, sum + lca(a, b, w));
    }
    
    printf("%lld\n", res);
    
    return 0;
}
