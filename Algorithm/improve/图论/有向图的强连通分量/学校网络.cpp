#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 110, M = 10010;

int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool instk[N];
int id[N], scc_cnt;
int ind[N], outd[N];
int n;

void add(int a, int b)
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
        ++ scc_cnt;
        do
        {
            y = stk[--top];
            instk[y] = false;
            id[y] = scc_cnt;
        }
        while(y != u);
    }
}

int main()
{
    scanf("%d", &n);
    
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++)
    {
        int b;
        while(scanf("%d", &b) == 1 && b)
        {
            add(i, b);
        }
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
            if(id[k] == id[i]) continue;
            ind[id[k]]++;
            outd[id[i]]++;
        }
    }
    
    int a = 0, b = 0;
    for(int i = scc_cnt; i; i--)
    {
        if(!ind[i]) a++;
        if(!outd[i]) b++;
    }
    
    if(scc_cnt == 1) printf("%d\n%d\n", a, 0);
    else printf("%d\n%d\n", a, max(a, b));
    
    return 0;
}
