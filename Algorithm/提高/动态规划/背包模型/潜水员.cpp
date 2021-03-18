#include<iostream>
#include<cstring>
using namespace std;

const int N = 50, M = 90;

int dp[N][M];

int main()
{
    int m1, m2, n; scanf("%d%d%d", &m1, &m2, &n);
    // dp[i][j]: 氧气容量至少为i，氮气容量至少为j的最少重量
    
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i = 0; i < n; i++)
    {
        int v, m, w; scanf("%d%d%d", &v, &m, &w);
        for(int j = m1; j >= 0; j--)
        {
            for(int k = m2; k >= 0; k--)
            {
                dp[j][k] = min(dp[j][k], dp[max(0, j - v)][max(0, k - m)] + w);
            }
        }
    }
    
    printf("%d\n", dp[m1][m2]);
    
    return 0;
}
