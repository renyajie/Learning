#include<iostream>
using namespace std;

const int N = 510;

int a[N][N];
int f[N][N];

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= i + 1; j++)
        {
            f[i][j] = -1000000000;
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
        }
    }
    
    int res = -1000000000;
    for(int i = 1; i <= n; i++) res = max(res, f[n][i]);
    
    printf("%d\n", res);
    
    return 0;
}
