#include<iostream>
#include<cstring>
using namespace std;

const int N = 60, mod = 1e9 + 7;

int ne[N];
int dp[N][N];
char str[N];

int main()
{
    int n; scanf("%d%s", &n, str + 1);
    
    int m = strlen(str + 1);
    for(int i = 2, j = 0; i <= m; i++)
    {
        while(j && str[i] != str[j + 1]) j = ne[j];
        if(str[i] == str[j + 1]) j++;
        ne[i] = j;
    }
    
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(char k = 'a'; k <= 'z'; k++)
            {
                int u = j;
                while(u && k != str[u + 1]) u = ne[u];
                if(k == str[u + 1]) u++;
                if(u < m) dp[i + 1][u] = (dp[i + 1][u] + dp[i][j]) % mod;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < m; i++) ans = (ans + dp[n][i]) % mod;
    
    printf("%d\n", ans);
    
    return 0;
}
