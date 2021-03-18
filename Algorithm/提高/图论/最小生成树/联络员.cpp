#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 2010, M = 10010;

struct Edge
{
    int a, b, w;
    bool operator< (const Edge &W) const
    {
        return w < W.w;
    }
}e[M];

int p[N];
int n, m;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) p[i] = i;
    
    int ans = 0;
    int k = 0;
    for(int i = 0; i < m; i++)
    {
        int t, a, b, w; scanf("%d%d%d%d", &t, &a, &b, &w);
        if(t == 1)
        {
            p[find(a)] = find(b);
            ans += w;
        }
        else
        {
            e[k++] = {a, b, w};
        }
    }
    
    sort(e, e + k);
    for(int i = 0; i < k; i++)
    {
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if(a != b)
        {
            ans += w;
            p[a] = b;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
