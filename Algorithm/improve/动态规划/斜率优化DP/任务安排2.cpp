#include<iostream>
using namespace std;

const int N = 3e5 + 10;

typedef long long ll;

ll t[N], c[N];
ll dp[N];
int q[N];

int main()
{
    int n, s; scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &t[i], &c[i]);
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }
    
    int hh = 0, tt = -1;
    q[++tt] = 0;
    for(int i = 1; i <= n; i++)
    {
        while(hh < tt && (dp[q[hh + 1]] - dp[q[hh]]) <= (t[i] + s) * (c[q[hh + 1]] - c[q[hh]])) hh++;
        dp[i] = dp[q[hh]] + (c[i] - c[q[hh]]) * t[i] + s * (c[n] - c[q[hh]]);
        while(hh < tt && (dp[q[tt]] - dp[q[tt - 1]]) * (c[i] - c[q[tt]]) >= (dp[i] - dp[q[tt]]) * (c[q[tt]] - c[q[tt - 1]])) tt--;
        q[++tt] = i;
    }
    
    printf("%lld\n", dp[n]);
    
    return 0;
}
