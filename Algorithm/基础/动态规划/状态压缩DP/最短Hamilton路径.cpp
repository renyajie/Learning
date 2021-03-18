#include<iostream>
#include<cstring>
using namespace std;

const int N = 30;

int g[N][N];
int f[1<<21][N];

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    
    memset(f, 0x3f, sizeof f);
    
    f[1][0] = 0;
    for(int i = 0; i < 1 << n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if((i >> j & 1) && (i >> k & 1))
                {
                    f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + g[k][j]);
                }
            }
        }
    }
    
    
    printf("%d\n", f[(1 << n) - 1][n - 1]);
    
    return 0;
}

