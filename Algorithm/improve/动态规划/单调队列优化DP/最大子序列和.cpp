#include<iostream>
using namespace std;

const int N = 300010;

int dp[N];
int q[N];
int s[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    
    int hh = 0, tt = -1;
    q[++tt] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(hh <= tt && q[hh] < i - m) hh++;
        dp[i] = s[i] - s[q[hh]];
        while(hh <= tt && s[q[tt]] >= s[i]) tt--;
        q[++tt] = i;
    }
    
    int ans = -1e9;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    
    printf("%d\n", ans);
    
    return 0;
}
