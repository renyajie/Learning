#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 10010, M = 50010;

int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool instk[N];
int id[N], sz[N], scc_cnt;
int out_d[N];
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ timestamp;
    stk[top++] = u, instk[u] = true;
    
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if(instk[j]) low[u] = min(low[u], dfn[j]);
    }
    
    if(dfn[u] == low[u])
    {
        ++scc_cnt;
        int y;
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
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        add(a, b);
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j];
            if(id[i] == id[k]) continue;
            
            out_d[id[i]]++;
        }
    }
    
    int ans = 0, zeros = 0;
    for(int i = scc_cnt; i; i--)
    {
        if(out_d[i] == 0)
        {
            zeros++;
            ans += sz[i];
            if(zeros > 1)
            {
                ans = 0;
                break;
            }
        }
        
    }
    
    printf("%d\n", ans);
    
    return 0;
}
