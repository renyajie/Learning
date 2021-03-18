#include<iostream>
using namespace std;

const int N = 1010;

int dp[N];

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        int v, w, s; scanf("%d%d%d", &v, &w, &s);
        if(s == 0)
        {
            for(int j = v; j <= m; j++) dp[j] = max(dp[j], dp[j - v] + w);
        }
        else
        {
            if(s == -1) s = 1;
            for(int j = 1; j <= s; j *= 2)
            {
                for(int k = m; k >= j * v; k--) dp[k] = max(dp[k], dp[k - j * v] + j * w);
                s -= j;
            }
            if(s)
            {
                for(int k = m; k >= s * v; k--) dp[k] = max(dp[k], dp[k - s * v] + s * w);
            }
        }
    }
    
    printf("%d\n", dp[m]);
    
    return 0;
}
