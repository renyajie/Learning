#include<iostream>
using namespace std;

const int N = 310;

int sum[N];
int f[N][N];
int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) scanf("%d", &sum[i]);
    
    for(int i = 1; i <= n; i++) sum[i] += sum[i - 1];
    
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i + len - 1 <= n; i++)
        {
            int l = i, r = i + len - 1;
            f[l][r] = 1000000000;
            for(int k = i; k < r; k++)
            {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    
    printf("%d\n", f[1][n]);
    
    return 0;
}
