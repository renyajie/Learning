#include<iostream>
#include<vector>
using namespace std;

const int N = 12;

int dp[N][10];

void init()
{
    for(int i = 0; i < 10; i++) dp[1][i] = 1;
    for(int i = 2; i < N; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                if(abs(j - k) >= 2) dp[i][j] += dp[i - 1][k];
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
    
    int ans = 0, last = -2;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        
        // 特判没有前导0
        for(int j = i == nums.size() - 1; j < x; j++)
        {
            if(abs(j - last) >= 2) ans += dp[i + 1][j];
        }
        
        if(abs(x - last) < 2) break;
        last = x;
        
        if(!i) ans++;
        //printf("i: %d, x: %d, ans: %d\n", i, x, ans);
    }
    
    if(nums.size() == 1) ans++;
    else
    {
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = i != 1; j < 10; j++)
            {
                ans += dp[i][j];
            }
            //printf("next: i: %d, ans: %d\n", i, ans);
        }
    }
    return ans;
}

int main()
{
    init();
    
    int a, b; scanf("%d%d", &a, &b);
    printf("%d\n", dfs(b) - dfs(a - 1));
    
    return 0;
}
