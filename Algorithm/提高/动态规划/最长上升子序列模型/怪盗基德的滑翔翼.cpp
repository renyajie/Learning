#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;

int a[N], dp[N];

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        
        for(int i = n - 1; i >= 0; i--)
        {
            dp[i] = 1;
            for(int j = i; j < n; j++)
            {
                if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
