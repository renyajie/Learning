#include<iostream>
using namespace std;

const int N = 1e5 + 10;

int dp[N][3];

int main()
{
    int n; scanf("%d", &n);
    
    dp[0][2] = 0, dp[0][0] = dp[0][1] = -0x3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        int w; scanf("%d", &w);
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - w);
        dp[i][1] = dp[i - 1][0] + w;
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
    }
    
    printf("%d\n", max(dp[n][1], dp[n][2]));
    
    return 0;
}
