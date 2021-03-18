#include<iostream>
#include<vector>
using namespace std;

const int N = 12;

int dp[N][10];

void init()
{
    for(int i = 0; i < 10; i++)
    {
        if(i != 4) dp[1][i] = 1;
    }
    
    for(int i = 2; i < N; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j == 4) continue;
            for(int k = 0; k < 10; k++)
            {
                if(k == 4) continue;
                if(j * 10 + k == 62) continue;
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
}

int dfs(int n)
{
    if(!n) return 1;
    
    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10;
    
    int ans = 0, last = 0;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for(int j = 0; j < x; j++)
        {
            if(j == 4) continue;
            if(last * 10 + j == 62) continue;
            ans += dp[i + 1][j];
        }
        
        if(x == 4) break;
        if(last * 10 + x == 62) break;
        last = x;
        
        if(!i) ans++;
    }
    
    return ans;
}

int main()
{
    init();
    
    int n, m;
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        printf("%d\n", dfs(m) - dfs(n - 1));
    }
    
    return 0;
}
