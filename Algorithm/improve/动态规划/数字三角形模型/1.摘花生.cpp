#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;

int a[N][N];
int dp[N][N];

int main()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int r, c; scanf("%d%d", &r, &c);
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                scanf("%d", &a[i][j]);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
        printf("%d\n", dp[r][c]);
    }
    return 0;
}
