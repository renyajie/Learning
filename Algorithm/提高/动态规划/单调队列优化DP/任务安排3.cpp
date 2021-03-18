#include<iostream>
using namespace std;

const int N = 3e5 + 10;

typedef long long ll;

ll c[N], t[N];
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
        int l = hh, r = tt;
        while(l < r)
        {
            int mid = l + r >> 1;
            if((dp[q[mid + 1]] - dp[q[mid]]) > (t[i] + s) * (c[q[mid + 1]] - c[q[mid]])) r = mid;
            else l = mid + 1;
        }
        int j = q[l];
        dp[i] = dp[j] + (c[i] - c[j]) * t[i] + s * (c[n] - c[j]);
        while(hh < tt && (__int128)(dp[q[tt]] - dp[q[tt - 1]]) * (c[i] - c[q[tt]]) >= (__int128)(dp[i] - dp[q[tt]]) * (c[q[tt]] - c[q[tt - 1]])) tt--;
        q[++tt] = i;
    }
    
    printf("%lld\n", dp[n]);
    
    return 0;
}
