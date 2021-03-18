#include<iostream>
using namespace std;

const int N = 40;

int a[N];
int dp[N][N];
int g[N][N];

void dfs(int l, int r)
{
    if(l > r)  return;
    int u = g[l][r];
    printf("%d ", g[l][r]);
    dfs(l, u - 1);
    dfs(u + 1, r);
}

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    for(int len = 1; len <= n; len++)
    {
        for(int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if(len == 1) 
            {
                dp[i][j] = a[i];
                g[i][j] = i;
            }
            else
            {
                for(int k = i; k <= j; k++)
                {
                    int left = k == i ? 1 : dp[i][k - 1];
                    int right = k == j ? 1 : dp[k + 1][j];
                    int v = left * right + a[k];
                    if(v > dp[i][j])
                    {
                        dp[i][j] = v;
                        g[i][j] = k;
                    }
                }
            }
        }
    }
    
    printf("%d\n", dp[1][n]);
    
    dfs(1, n);
    
    return 0;
}
