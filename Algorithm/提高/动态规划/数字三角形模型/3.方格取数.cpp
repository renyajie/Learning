#include<iostream>
using namespace std;

const int N = 20;

int a[N][N];
int dp[2*N][N][N];

int main()
{
    int n; scanf("%d", &n);
    int x, y, v;
    while(scanf("%d%d%d", &x, &y, &v) && (x || y || v)) a[x][y] = v;
    for(int k = 2; k <= 2 * n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(i >= k) continue;
            for(int j = 1; j <= n; j++)
            {
                if(j >= k) continue;
                dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j]);
                dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-1][j]);
                dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j-1]);
                dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-1][j-1]);
                dp[k][i][j] += a[i][k-i];
                if(j != i) dp[k][i][j] += a[j][k-j];
            }
        }
    }
    printf("%d\n", dp[2*n][n][n]);
    return 0;
}
