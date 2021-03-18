#include<iostream>
using namespace std;

const int N = 3010;

typedef long long ll;

ll dp[N];

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        int v; scanf("%d", &v);
        for(int j = v; j <= m; j++) dp[j] += dp[j - v];
    }
    
    printf("%lld\n", dp[m]);
    
    return 0;
}
