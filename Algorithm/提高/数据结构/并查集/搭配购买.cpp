#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 10010, M = 10010;

int p[N], v[N], w[N], dp[N];
int n, k, m;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
    
    for(int i = 1; i < N; i++) p[i] = i;
    for(int i = 0; i < k; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        int pa = find(a), pb = find(b);
        if(pa != pb)
        {
            p[pa] = pb;
            v[pb] += v[pa], w[pb] += w[pa];
        }
    }
    
    for(int i = 1; i <= n; i++)
        if(p[i] == i)
            for(int j = m; j >= v[i]; j--)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
                
    printf("%d\n", dp[m]);
    return 0;
}
