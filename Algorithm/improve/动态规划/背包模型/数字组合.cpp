#include<iostream>
using namespace std;

const int N = 10010;

int dp[N];

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        int v; scanf("%d", &v);
        for(int j = m; j >= v; j--)
        {
            dp[j] += dp[j - v];
        }
    }
    
    printf("%d\n", dp[m]);
    
    return 0;
}
