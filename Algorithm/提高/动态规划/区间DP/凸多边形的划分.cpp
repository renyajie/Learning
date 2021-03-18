#include<iostream>
#include<cstring>
using namespace std;

const int N = 50, M = 35;

typedef long long ll;

ll a[N];
ll dp[N][N][M];

void mul(ll a[], ll b)
{
    ll t = 0;
    for(int i = 0; i < M; i++)
    {
        t += a[i] * b;
        a[i] = t % 10;
        t /= 10;
    }
}

void add(ll a[], ll b[])
{
    ll t = 0;
    for(int i = 0; i < M; i++)
    {
        t += a[i] + b[i];
        a[i] = t % 10;
        t /= 10;
    }
}

int cmp(ll a[], ll b[])
{
    for(int i = M - 1; i >= 0; i--)
    {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
    }
    return 0;
}

void print(ll a[])
{
    int k = M - 1;
    while(k && a[k] == 0) k--;
    while(k >= 0) printf("%lld", a[k--]);
}

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    
    ll tmp[M];
    for(int len = 3; len <= n; len++)
    {
        for(int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            dp[i][j][M - 1] = 1;
            for(int k = i + 1; k < j; k++)
            {
                memset(tmp, 0, sizeof tmp);
                tmp[0] = 1;
                mul(tmp, a[i]);
                mul(tmp, a[k]);
                mul(tmp, a[j]);
                add(tmp, dp[i][k]);
                add(tmp, dp[k][j]);
                if(cmp(dp[i][j], tmp) > 0)
                {
                    memcpy(dp[i][j], tmp, sizeof tmp);
                }
            }
        }
    }
    
    print(dp[1][n]);
    
    return 0;
}
