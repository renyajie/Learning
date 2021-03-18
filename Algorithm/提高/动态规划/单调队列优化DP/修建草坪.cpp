#include<iostream>
using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

ll s[N];
ll dp[N];
int q[N];

ll g(int i)
{
    if(!i) return 0;
    return dp[i - 1] - s[i];
}

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }
    
    int hh = 0, tt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(hh <= tt && q[hh] < i - m) hh++;
        dp[i] = max(dp[i - 1], g(q[hh]) + s[i]);
        while(hh <= tt && g(q[tt]) <= g(i)) tt--;
        q[++tt] = i;
    }
    
    printf("%lld\n", dp[n]);
    
    return 0;
}
