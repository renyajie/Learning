#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 10010, M = 30010;

int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int ans; // 统计一个割点所连接的点双连通块最大值
int n, m;
int root;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++timestamp;
    
    int cnt = 0; // 统计若u是割点，u所连接的点双连通块的数量
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if(dfn[u] <= low[j]) // j不能到达u之前，说明找到一个点双连通块
            {
                cnt++;
            }
        }
        else low[u] = min(low[u], dfn[j]);
    }
    
    if(u != root) cnt++; // 如果u不是根节点，则到达u的路径也是一个点双连通块，数量加1
    
    ans = max(ans, cnt);
}

int main()
{
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(h, -1, sizeof h);
        idx = timestamp = ans = root = 0;
        
        for(int i = 0; i < m; i ++)
        {
            int a, b; scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
        }
        
        int cnt = 0;
        for(root = 0; root < n; root++)
        {
            if(!dfn[root])
            {
                cnt++;
                tarjan(root);
            }
        }
        
        printf("%d\n", ans + cnt - 1);
    }
    
    return 0;
}
