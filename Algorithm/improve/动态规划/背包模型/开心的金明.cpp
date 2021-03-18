#include<iostream>
using namespace std;

const int N = 30010;

int dp[N];

int main()
{
    int m, n; scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++)
    {
        int v, w; scanf("%d%d", &v, &w);
        for(int j = m; j >= v; j--)
        {
            dp[j] = max(dp[j], dp[j - v] + v * w);
        }
    }
    
    printf("%d\n", dp[m]);
    
    return 0;
}
