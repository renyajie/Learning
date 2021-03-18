#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010, M = 600010;

typedef long long ll;

int h[N], hs[N], e[M], ne[M], w[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool instk[N];
int id[N], sz[N], scc_cnt;
int dist[N];
int n, m;

void add(int h[], int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
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
        else if(instk[j]) low[u] = min(low[u], dfn[j]);
    }
    
    if(dfn[u] == low[u])
    {
        int y;
        ++ scc_cnt;
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
    memset(hs, -1, sizeof hs);
    for(int i = 1; i <= n; i++)
    {
        add(h, 0, i, 1);
    }
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &c, &a, &b);
        if(c == 1) add(h, b, a, 0), add(h, a, b, 0);
        else if(c == 2) add(h, a, b, 1);
        else if(c == 3) add(h, b, a, 0);
        else if(c == 4) add(h, b, a, 1);
        else add(h, a, b, 0);
    }
    
    tarjan(0);
    
    bool success = true;
    for(int i = 0; i <= n; i++)
    {
        for(int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j];
            int a = id[i], b = id[k];
            if(a != b)
            {
                add(hs, a, b, w[j]);
            }
            else if(w[j] > 0)
            {
                success = false;
                break;
            }
        }
        if(!success) break;
    }
    
    if(!success) puts("-1");
    else
    {
        for(int i = scc_cnt; i; i--)
        {
            for(int j = hs[i]; ~j; j = ne[j])
            {
                int k = e[j];
                dist[k] = max(dist[k], dist[i] + w[j]);
            }
        }
        
        ll res = 0;
        for(int i = 1; i <= scc_cnt; i++)
        {
            res += (ll)dist[i] * sz[i];
        }
        
        printf("%lld\n", res);
    }
    
    return 0;
}
