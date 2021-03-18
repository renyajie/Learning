#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;

int dp[N][N];
int e[N], ne[N], h[N], idx;
int v[N], w[N];
int n, m;

void init()
{
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    for(int i = h[u]; ~i; i = ne[i])
    {
        int son = e[i];
        dfs(son);
        for(int k = m; k >= 0; k--)
        {
            for(int j = 0; j <= k; j++)
            {
                dp[u][k] = max(dp[u][k], dp[u][k - j] + dp[son][j]);
            }
        }
    }
    
    for(int j = m; j >= v[u]; j--) dp[u][j] = dp[u][j - v[u]] + w[u];
    for(int j = 0; j < v[u]; j++) dp[u][j] = 0;
}

int main()
{
    init();
    
    scanf("%d%d", &n, &m);
    int root;
    for(int i = 1; i <= n; i++)
    {
        int p; scanf("%d%d%d", &v[i], &w[i], &p);
        
        if(p == -1) root = i;
        else add(p, i);
    }
    
    dfs(root);
    
    printf("%d\n", dp[root][m]);
    
    return 0;
}
