#include<iostream>
using namespace std;

const int N = 110;

int a[N][N];
int dp[N][N];

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++) 
    {
        dp[i][1] = dp[i-1][1] + a[i][1];
        dp[1][i] = dp[1][i-1] + a[1][i];
    }
    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= n; j++)
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
    printf("%d\n", dp[n][n]);
    return 0;
}
