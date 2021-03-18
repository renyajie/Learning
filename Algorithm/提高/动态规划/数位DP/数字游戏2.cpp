#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

typedef long long ll;

const int M = 15;

ll dp[M][11][110];
int N;

int mod(int a, int b)
{
    return (a % b + b) % b;
}

void init()
{
    for(int i = 0; i < 10; i++) dp[1][i][i % N] = 1;
    for(int i = 2; i < M; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int m = 0; m < N; m++)
            {
                for(int k = 0; k < 10; k++)
                {
                    dp[i][j][m] += dp[i - 1][k][mod(m - j, N)];
                }
            }
        }
    }
    
}

ll dfs(int n)
{
    //printf("-----\n");
    if(!n) return 1;
    
    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10;
    
    //printf("haha\n");
    
    ll ans = 0;
    int last = 0;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for(int j = 0; j < x; j++)
        {
            ans += dp[i + 1][j][mod(-last, N)];
        }
        
        last = mod(last + x, N);
        
        if(!i && last % N == 0) ans++;
        //printf("i:%d, last:%d, ans:%d\n", i, last, ans);
    }
    
    return ans;
}

int main()
{
    int a, b; 
    while(scanf("%d%d%d", &a, &b, &N) == 3)
    {
        memset(dp, 0, sizeof dp);
        init();
    
        printf("%lld\n", dfs(b) - dfs(a - 1));
    }
    
    return 0;
}
