#include<iostream>
using namespace std;

const int N = 3010;

int a[N], b[N];
int dp[N][N];

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    
    
    for(int i = 1; i <= n; i++)
    {
        int maxv = 1;
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], maxv);
            
            if(b[j] < a[i]) maxv = max(maxv, dp[i - 1][j] + 1);
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
    
    return 0;
}
