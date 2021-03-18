#include<iostream>
#include<vector>
using namespace std;

const int N = 35;

int dp[N][10];

void init()
{
    for(int i = 0; i < 10; i++) dp[1][i] = 1;
    for(int i = 2; i < N; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = j; k < 10; k++)
            {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
}

int dfs(int n)
{
    //printf("----\n");
    if(!n) return 1;
    
    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10;
    
    int ans = 0, last = 0;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        
        for(int j = 0; j < x; j++)
        {
            if(j >= last) ans += dp[i + 1][j];
        }
        
        
        if(x < last) break;
        last = x;
        
        if(!i) ans++;
    }
    
    return ans;
}

int main()
{
    init();
    
    int a, b; 
    
    while(scanf("%d%d", &a, &b) == 2) printf("%d\n", dfs(b) - dfs(a - 1));
    
    return 0;
}
