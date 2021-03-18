#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 110, M = 210;

struct Edge
{
    int a, b, w;
    bool operator< (const Edge& W) const
    {
        return w < W.w;
    }
}e[M];

int p[N];
int n, k;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++)
    {
        int a, b, w; scanf("%d%d%d", &a, &b, &w);
        e[i] = {a, b, w};
    }
    
    sort(e, e + k);
    
    for(int i = 1; i <= n; i++) p[i] = i;
    
    int ans = 0;
    for(int i = 0; i < k; i++)
    {
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if(a == b)
        {
            ans += w;
        }
        else
        {
            p[a] = b;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
