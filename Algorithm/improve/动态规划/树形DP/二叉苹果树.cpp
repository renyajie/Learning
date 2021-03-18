#include<iostream>
#include<cstring>
using namespace std;

const int N = 110, M = 2 * N;

int h[N], e[M], ne[M], w[M], idx;
int dp[N][N];
int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int father)
{
    if(h[u] == -1) return;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int son = e[i];
        if(son == father) continue;
        dfs(son, u);
        for(int j = m; j >= 0; j--)
        {
            for(int k = 0; k < j; k++)
            {
                dp[u][j] = max(dp[u][j], dp[u][j - k - 1] + dp[son][k] + w[i]);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    dfs(1, -1);
    
    printf("%d\n", dp[1][m]);
    
    return 0;
}
