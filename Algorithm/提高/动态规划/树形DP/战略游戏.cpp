#include<iostream>
#include<cstring>
using namespace std;

const int N = 1510;

int h[N], e[N], ne[N], idx;
int dp[N][2];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    dp[u][1] = 1, dp[u][0] = 0;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        dp[u][1] += min(dp[j][0], dp[j][1]);
        dp[u][0] += dp[j][1];
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        memset(h, -1, sizeof h);
        memset(st, 0, sizeof st);
        idx = 0;
        for(int i = 0; i < n; i++)
        {
            int a, cnt, b;
            scanf("%d:(%d) ", &a, &cnt);
            while(cnt) 
            {
                scanf("%d", &b);
                add(a, b);
                cnt--;
                st[b] = true;
            }
        }
        
        int root = 0;
        while(st[root]) root++;
        
        dfs(root);
        
        printf("%d\n", min(dp[root][0], dp[root][1]));
    }
    
    return 0;
}
