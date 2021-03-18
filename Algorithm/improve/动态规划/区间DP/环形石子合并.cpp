#include<iostream>
#include<cstring>
using namespace std;

const int N = 410;

int a[N];
int f[N][N], g[N][N];
int sum[N];

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    
    for(int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + a[i];
    
    memset(g, 0x3f, sizeof g);
    memset(f, -0x3f, sizeof f);
    
    for(int len = 1; len <= n; len++)
    {
        for(int i = 1; i + len - 1 <= 2 * n; i++)
        {
            int j = i + len - 1;
            if(len == 1) f[i][j] = g[i][j] = 0;
            else 
            {
                for(int k = i; k < j; k++)
                {
                    f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
                    g[i][j] = min(g[i][j], g[i][k] + g[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }
    }
    
    int maxv = 0, minv = 0x3f3f3f3f;
    for(int i = 1; i + n - 1 <= 2 * n; i++) 
    {
        maxv = max(maxv, f[i][i + n - 1]);
        minv = min(minv, g[i][i + n - 1]);
    }
    
    printf("%d\n%d\n", minv, maxv);
    
    return 0;
}
