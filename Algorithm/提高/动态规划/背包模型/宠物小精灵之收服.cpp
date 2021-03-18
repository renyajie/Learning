#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010, M = 510, K = 110;

int dp[N][M];

int main()
{
    int V1, V2, n; scanf("%d%d%d", &V1, &V2, &n);
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++)
    {
        int v1, v2; scanf("%d%d", &v1, &v2);
        for(int j = V1; j >= v1; j--) // 二维费用背包，01背包多一个“体积”
        {
            for(int k = V2 - 1; k >= v2; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - v1][k - v2] + 1);
            }
        }
    }
    
    printf("%d ", dp[V1][V2 - 1]);
    
    int k = V2 - 1;
    while(k > 0 && dp[V1][k - 1] == dp[V1][V2 - 1]) k--;
    printf("%d\n", V2 - k);
    
    return 0;
}
