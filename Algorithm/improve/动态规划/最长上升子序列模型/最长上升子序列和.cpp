#include<iostream>
using namespace std;

const int N = 1010;

int a[N];
int dp[N];

int main()
{
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for(int i = 0; i < n; i++)
    {
        dp[i] = a[i];
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
    
    return 0;
}
