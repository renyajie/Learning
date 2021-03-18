#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 310, M = 8010;

struct Edge
{
    int a, b, w;
    bool operator< (const Edge& W) const
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
    for(int i = 0; i < m; i++)
    {
        int a, b, w; scanf("%d%d%d", &a, &b, &w);
        e[i] = {a, b, w};
    }
    
    sort(e, e + m);
    
    for(int i = 1; i <= n; i++) p[i] = i;
    
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if(a != b)
        {
            p[a] = b;
            ans = w;
        }
    }
    
    printf("%d %d\n", n - 1, ans);
    
    return 0;
}
