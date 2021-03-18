#include<iostream>
#include<cstring>
using namespace std;

const int N = 5010;

int t[N], c[N];
int dp[N];

int main()
{
    int n, s; scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &t[i], &c[i]);
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }
    
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i] = min(dp[i], dp[j] + (c[i] - c[j]) * t[i] + s * (c[n] - c[j]));
        }
    }
    
    printf("%d\n", dp[n]);
    
    return 0;
}
