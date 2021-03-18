#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 6010, M = 6010;

struct Edge 
{
    int a, b, w;
    bool operator< (const Edge & W) const
    {
        return w < W.w;
    }
}e[M];

int p[N], sz[N];
int n;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n; scanf("%d", &n);
        int m = n - 1;
        for(int i = 0; i < m; i++)
        {
            int a, b, w; scanf("%d%d%d", &a, &b, &w);
            e[i] = {a, b, w};
        }
        
        sort(e, e + m);
        
        for(int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
        
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
            if(a != b)
            {
                ans += (sz[b] * sz[a] - 1) * (w + 1);
                p[a] = b;
                sz[b] += sz[a];
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
