#include<iostream>
#include<vector>
using namespace std;

const int N = 110, M = 12;

vector<int> st;
int dp[2][1 << M][1 << M];
int g[N];
int cnt[1 << M];
int n, m;

bool check(int state)
{
    for(int i = 0; i < m; i++)
    {
        if((state >> i & 1) && ((state >> i + 1 & 1) || state >> i + 2 & 1)) return false; // 注意这里不是全&&
    }
    return true;
}

int count(int t)
{
    int ans = 0;
    for(int i = 0; i < m; i++) ans += t >> i & 1;
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char c; cin >> c;
            if(c == 'H') g[i] += 1 << j;
        }
    }
    
    for(int i = 0; i < 1 << m; i++)
    {
        if(check(i)) 
        {
            st.push_back(i);
            cnt[i] = count(i);
        }
    }
    
    for(int i = 1; i <= n + 2; i++)
    {
        for(int a = 0; a < st.size(); a++)
        {
            for(int b = 0; b < st.size(); b++)
            {
                for(int c = 0; c < st.size(); c++)
                {
                    if((st[c] & st[b]) | (st[a] & st[b]) | (st[a] & st[c])) continue;
                    if((g[i - 1] & st[a]) | (g[i] & st[b])) continue;
                    dp[i & 1][a][b] = max(dp[i & 1][a][b], dp[i - 1 & 1][c][a] + cnt[st[b]]);
                }
            }
        }
    }
    
    printf("%d\n", dp[n + 2 & 1][0][0]);
    
    return 0;
}
