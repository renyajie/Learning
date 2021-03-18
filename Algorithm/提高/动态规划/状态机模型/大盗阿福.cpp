#include<iostream>
using namespace std;

const int N = 1e5 + 10;

int dp[N][2];

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n; scanf("%d", &n);
        
        for(int i = 1; i <= n; i++)
        {
            int w; scanf("%d", &w);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + w;
        }
        
        printf("%d\n", max(dp[n][0], dp[n][1]));
    }
    
    return 0;
}
