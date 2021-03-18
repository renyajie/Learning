#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10, M = 1e5 + 10, P = 110;

int d[N];
int t[M];
int q[M];
ll dp[P][M];
ll s[M];
ll a[M];

ll y(int k, int j)
{
    return dp[j - 1][k] + s[k];
}

int main()
{
    int n, m, p; scanf("%d%d%d", &n, &m, &p);
    for(int i = 2; i <= n; i++)
    {
        scanf("%lld", &d[i]);
        d[i] += d[i - 1];
    }
    
    for(int i = 1; i <= m; i++)
    {
        int h;
        scanf("%d%lld", &h, &t[i]);
        a[i] = t[i] - d[h];
    }
    
    sort(a + 1, a + 1 + m);
    
    for(int i = 1; i <= m; i++) 
    {
        s[i] = s[i - 1] + a[i];
        //printf("%d", s[i]);
    }
    //printf("\n");
    
    memset(dp, 0x3f, sizeof dp);
    for(int i = 0; i <= p; i++) dp[i][0] = 0;
    
    for(int j = 1; j <= p; j++)
    {
        int hh = 0, tt = -1;
        q[++tt] = 0;
        for(int i = 1; i <= m; i++)
        {
            while(hh < tt && (y(q[hh + 1], j) - y(q[hh], j)) <= a[i] * (q[hh + 1] - q[hh])) hh++;
            int k = q[hh];
            dp[j][i] = dp[j - 1][k] + a[i] * (i - k) - s[i] + s[k];
            //printf("k: %d, dp[%d, %d] = %lld, dp[%d, %d] = %lld\n", k, j - 1, k , dp[j - 1][k], j, i, dp[j][i]);
            while(hh < tt && 
                        (y(q[tt], j) - y(q[tt - 1], j)) * (i - q[tt]) >= 
                        (q[tt] - q[tt - 1]) * (y(i, j) - y(q[tt], j))) tt--;
            q[++tt] = i;
        }
    }
    
    printf("%lld\n", dp[p][m]);
    
    return 0;
}
