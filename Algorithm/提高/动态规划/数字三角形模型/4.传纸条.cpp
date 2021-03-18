#include<iostream>
using namespace std;

const int N = 60;

int a[N][N];
int dp[2*N][N][N];

int main()
{
    int m, n; scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for(int k = 2; k <= (m+n); k++)
    {
        for(int i = 1; i <= m; i++)
        {
            if(i >= k) continue;
            for(int j = 1; j <= m; j++)
            {
                if(j >= k) continue;
                if(i == j && k != 2 && k != (m+n)) { dp[k][i][j] = -1000000000; continue; }
                dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j]);
                dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-1][j]);
                dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j-1]);
                dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-1][j-1]);
                dp[k][i][j] += a[i][k-i] + a[j][k-j];
            }
        }
    }
    printf("%d\n", dp[m+n][m][m]);
    return 0;
}
