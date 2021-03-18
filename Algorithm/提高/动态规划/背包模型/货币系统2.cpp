#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 25010, M = 110;

int dp[N];
int a[M];

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        
        int m = a[n - 1];
        int ans = 0;
        
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        
        for(int i = 0; i < n; i++)
        {
            if(!dp[a[i]]) ans++;
            for(int j = a[i]; j <= m; j++) dp[j] += dp[j - a[i]];
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}


