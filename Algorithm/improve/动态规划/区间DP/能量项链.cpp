#include<iostream>
using namespace std;

const int N = 210;

int dp[N][N];
int a[N];

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    
    for(int len = 3; len <= n + 1; len++)
    {
        for(int i = 1; i + len - 1 <= 2 * n; i++)
        {
            int j = i + len - 1;
            for(int k = i + 1; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[j] * a[k]);
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i + n <= 2 * n; i++) ans = max(ans, dp[i][i + n]);
    
    printf("%d\n", ans);
    
    return 0;
}
