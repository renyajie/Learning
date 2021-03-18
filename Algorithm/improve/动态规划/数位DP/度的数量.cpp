#include<iostream>
#include<vector>
using namespace std;

const int N = 40;

int dp[N][N]; // B进制下，i位数字，有M个1的个数
int K, B;

void init()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    
    
}

int dfs(int n)
{
    if(!n) return 0;
    
    vector<int> nums;
    while(n) nums.push_back(n % B), n /= B;
    
    //printf("%d\n", nums.size());
    
    int res = 0;
    int last = 0; // 之前有多少个1
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        
        if(x)
        {
            res += dp[i][K - last]; // 填0
            if(x > 1) // x > 1，统计完直接break；
            {
                if(K - last - 1 >= 0) res += dp[i][K - last - 1];
                break;
            }
            else 
            {
                last++;
                if(last > K) break;
            }
        }
        
        if(!i && last == K) res++;
    }
    
    return res;
}

int main()
{
    init();
    
    int x, y;
    scanf("%d%d%d%d", &x, &y, &K, &B);
    
    printf("%d\n", dfs(y) - dfs(x - 1));
    
    return 0;
}
