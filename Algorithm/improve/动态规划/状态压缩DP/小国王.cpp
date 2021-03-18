#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

const int N = 12, M = 1 << N;

vector<int> st;
vector<int> tran[M];
int cnt[M];
ll dp[N][N * N][M];
int n, m; 

bool check(int state)
{
    for(int i = 0; i < n; i++)
    {
        if(state >> i & 1 && state >> i + 1 & 1) return false;
    }
    return true;
}

int count(int t)
{
    int ans = 0;
    for(int i = 0; i < n; i++) ans += t >> i & 1;
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < 1 << n; i++)
    {
        if(check(i))
        {
            st.push_back(i);
            cnt[i] = count(i);
        }
    }
    
    for(int i = 0; i < st.size(); i++)
    {
        for(int j = 0; j < st.size(); j++)
        {
            if((st[i] & st[j]) == 0 && check(st[i] | st[j]))
            {
                tran[i].push_back(j);
            }
        }
    }
    
    
    dp[0][0][0] = 1;
    for(int i = 1; i <= n + 1; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            for(int k = 0; k < st.size(); k++)
            {
                for(int s : tran[k])
                {
                    int c = cnt[st[k]];
                    if(j < c) continue;
                    dp[i][j][k] += dp[i - 1][j - c][s];
                }
            }
        }
    }
    
    printf("%lld\n", dp[n + 1][m][0]);
    
    return 0;
}
