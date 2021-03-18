#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 10010, M = 110;

int dp[N];

struct stone
{
    int s, e, l;
    bool operator < (const stone & W) const 
    {
        return s * W.l < W.s * l;
    }
} stone[M];

int main()
{
    int T, kase = 0; scanf("%d", &T);
    while(T--)
    {
        int n; scanf("%d", &n);
        int m = 0;
        for(int i = 0; i < n; i++)
        {
            int s, e, l; scanf("%d%d%d", &s, &e, &l);
            stone[i] = {s, e, l};
            m += s;
        }
        sort(stone, stone + n);
        
        memset(dp, -0x3f, sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < n; i++)
        {
            int s = stone[i].s, e = stone[i].e, l = stone[i].l;
            for(int j = m; j >= s; j--) dp[j] = max(dp[j], dp[j - s] + max(0, e - (j - s) * l));
        }
        
        int ans = 0;
        for(int i = 0; i <= m; i++) ans = max(ans, dp[i]);
        
        printf("Case #%d: %d\n", ++kase, ans);
    }
    
    return 0;
}
