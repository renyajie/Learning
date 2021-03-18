#include<iostream>
#include<cstring>
using namespace std;

const int N = 12;

long long f[N][1 << N];
bool st[1 << N];

int main()
{
        
    int n, m;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        for (int i = 0; i < 1 << n; i ++ )
        {
            int cnt = 0;
            st[i] = true;
            for (int j = 0; j < n; j ++ )
                if (i >> j & 1)
                {
                    if (cnt & 1) st[i] = false;
                    cnt = 0;
                }
                else cnt ++ ;
            if (cnt & 1) st[i] = false;
        }
        
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 0; j < 1 << n; j++)
            {
                for(int k = 0; k < 1 << n; k++)
                {
                    if((j & k) || !st[j | k]) continue;
                    f[i][j] += f[i - 1][k];
                }
            }
        }
        
        printf("%lld\n", f[m][0]);
    }
    
    return 0;
}
