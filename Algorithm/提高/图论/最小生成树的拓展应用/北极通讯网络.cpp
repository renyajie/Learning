#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 510, M = 500010;

typedef pair<int,int> PII;

struct Edge
{
    int a, b;
    double w;
    bool operator< (const Edge& W) const
    {
        return w < W.w;
    }
}e[M];

int p[N];
int n, k;
PII pos[N];

double get_dis(PII a, PII b)
{
    int x = a.first - b.first;
    int y = a.second - b.second;
    return sqrt(x * x + y * y);
}

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d%d", &pos[i].first, &pos[i].second);
    
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            e[cnt++] = {i, j, get_dis(pos[i], pos[j])};
        }
    }
    
    for(int i = 1; i <= n; i++) p[i] = i;
    
    sort(e, e + cnt);
    double ans = 0;
    int size = n;
    for(int i = 0; i < cnt; i++)
    {
        if(size <= k) break;
        
        int a = find(e[i].a), b = find(e[i].b);
        double w = e[i].w;
        if(a != b)
        {
            p[a] = b;
            ans = w;
            size--;
        }
    }
    
    printf("%.2lf\n", ans);
    
    return 0;
}
