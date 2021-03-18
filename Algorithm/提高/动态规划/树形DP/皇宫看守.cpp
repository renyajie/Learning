#include<iostream>
#include<cstring>
using namespace std;

const int N = 1510;

int h[N], e[N], ne[N], w[N], idx;
int dp[N][3];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    dp[u][2] = w[u];
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        dp[u][0] += min(dp[j][1], dp[j][2]);
        dp[u][2] += min(dp[j][0], min(dp[j][1], dp[j][2]));
    }
    
    dp[u][1] = 0x3f3f3f3f;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dp[u][1] = min(dp[u][1], dp[j][2] + dp[u][0] - min(dp[j][1], dp[j][2]));
    }
}

int main()
{
    int n; scanf("%d", &n);
    
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++)
    {
        int a, cost, cnt; scanf("%d%d%d", &a, &cost, &cnt);
        w[a] = cost;
        while(cnt--)
        {
            int b; scanf("%d", &b);
            add(a, b);
            st[b] = true;
        }
    }
    
    int root = 1;
    while(st[root]) root++;
    
    
    dfs(root);
    
    printf("%d\n", min(dp[root][2], dp[root][1]));
    
    return 0;
}
