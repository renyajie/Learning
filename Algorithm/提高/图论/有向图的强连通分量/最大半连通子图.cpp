#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>
using namespace std;

const int N = 100010, M = 2000010;

typedef long long ll;

int h[N], hs[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool instk[N];
int id[N], sz[N], scc_cnt;
int dp[N], g[N];
int n, m, mod;

void add(int h[], int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++timestamp;
    stk[top++] = u, instk[u] = true;
    
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if(instk[j])
        {
            low[u] = min(low[u], dfn[j]);
        }
    }
    
    if(dfn[u] == low[u])
    {
        int y;
        ++scc_cnt;
        do
        {
            y = stk[--top];
            instk[y] = false;
            id[y] = scc_cnt;
            sz[scc_cnt]++;
        }
        while(y != u);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &mod);
    
    memset(h, -1, sizeof h);
    memset(hs, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        add(h, a, b);
    }
    
    //exit(0);
    
    for(int i = 1; i <= n; i++)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
    
    
    
    unordered_set<ll> used;
    for(int i = 1; i <= n; i++)
    {
        for(int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j];
            int a = id[i], b = id[k];
            if(a != b && !used.count(a * 100000ll + b))
            {
                add(hs, a, b);
                used.insert(a * 100000ll + b);
            }
        }
    }
    
    
    
    for(int i = scc_cnt; i; i--)
    {
        if(!dp[i]) dp[i] = sz[i], g[i] = 1; // 初始化每个起点
        
        for(int j = hs[i]; ~j; j = ne[j])
        {
            int k = e[j];
            if(dp[k] < dp[i] + sz[k])
            {
                dp[k] = dp[i] + sz[k];
                g[k] = g[i];
            }
            else if(dp[k] == dp[i] + sz[k])
            {
                g[k] = (g[k] + g[i]) % mod;
            }
        }
    }
    
    
    
    int ans = 0, sum = 0;
    for(int i = 1; i <= scc_cnt; i++)
    {
        if(dp[i] > ans)
        {
            ans = dp[i];
            sum = g[i];
        }
        else if(dp[i] == ans)
        {
            sum = (sum + g[i]) % mod;
        }
    }
    
    printf("%d\n%d\n", ans, sum);
    
    return 0;
}
