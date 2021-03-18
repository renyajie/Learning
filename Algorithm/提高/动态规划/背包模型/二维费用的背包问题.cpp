#include<iostream>
using namespace std;

const int N = 110;

int dp[N][N];

int main()
{
    int n, m1, m2; scanf("%d%d%d", &n, &m1, &m2);
    for(int i = 0; i < n; i++)
    {
        int v, m, w; scanf("%d%d%d", &v, &m, &w);
        for(int j = m1; j >= v; j--)
        {
            for(int k = m2; k >= m; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - v][k - m] + w);
            }
        }
    }
    
    printf("%d\n", dp[m1][m2]);
    
    return 0;
}
