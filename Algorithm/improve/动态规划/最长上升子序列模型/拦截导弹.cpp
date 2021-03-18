#include<iostream>
using namespace std;

const int N = 1010;

int a[N];
int dp[N];
int g[N];

int main()
{
    int n = 0;
    while(cin >> a[n]) n++;
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[j] >= a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    
    printf("%d\n", ans);
    
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int k = 0;
        while(k < cnt && a[i] > g[k]) k++;
        g[k] = a[i];
        if(k >= cnt) cnt++;
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
