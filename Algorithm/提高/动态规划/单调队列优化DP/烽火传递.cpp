#include<iostream>
using namespace std;

const int N = 2e5 + 10;

int a[N];
int q[N];
int dp[N]; // dp[i]：前i个烽火台，且点亮第i个烽火台的最小值

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    int hh = 0, tt = - 1;
    q[++tt] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(hh <= tt && q[hh] < i - m) hh++;
        dp[i] = dp[q[hh]] + a[i];
        while(hh <= tt && dp[q[tt]] >= dp[i]) tt--;
        q[++tt] = i;
    }
    
    int ans = 1e9;
    for(int i = n - m + 1; i <= n; i++) ans = min(ans, dp[i]);
    
    printf("%d\n", ans);
    
    return 0;
}
