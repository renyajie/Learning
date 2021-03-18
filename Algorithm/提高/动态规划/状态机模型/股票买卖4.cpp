#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10, M = 110;

int dp[N][M][2];

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    
    memset(dp, -0x3f, sizeof dp);
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++) dp[i][0][0] = 0;
    
    for(int i = 1; i <= n; i++)
    {
        int w; scanf("%d", &w);
        for(int j = 1; j <= m; j++)
        {
            dp[i][j][1] = max(dp[i - 1][j - 1][0] - w, dp[i - 1][j][1]);
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + w);
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= m; i++) ans = max(ans, dp[n][i][0]);
    
    printf("%d\n", ans);
    
    return 0;
}
