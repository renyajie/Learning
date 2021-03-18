#include<iostream>
using namespace std;

const int N = 20, M = 25;

int w[N][M];
int dp[N][M];
int g[N];

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }
    
    for(int i = n; i >= 1; i--) // 倒序遍历，可以用于倒推字典序最小的情况
    {
        for(int j = m; j >= 0; j--)
        {
            for(int k = 0; k <= j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i + 1][j - k] + w[i][k]);
            }
        }
    }
    
    printf("%d\n", dp[1][m]);
    
    int k = m;
    for(int i = 1; i <= n; i++) 
    {
        for(int j = 0; j <= k; j++)
        {
            if(dp[i][k] == dp[i + 1][k - j] + w[i][j])
            {
                k -= j;
                g[i] = j;
                break;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) printf("%d %d\n", i, g[i]);
    
    return 0;
}
