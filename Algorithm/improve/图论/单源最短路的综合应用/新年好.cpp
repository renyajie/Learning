#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 50010, M = 2e5 + 10;

typedef pair<int,int> PII;

int h[N], e[M], ne[M], w[M], idx;
int pos[6];
int dist[6][N];
int n, m;
bool st[N];
int ans;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start, int d[])
{
    memset(dist, 0x3f, 4 * N); // 如果数组作为函数的形参，那么sizeof运算符无法正确获取数组的长度。
    dist[start] = 0;
    
    memset(st, false, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});
    
    while(pq.size())
    {
        PII p = pq.top(); pq.pop();
        int u = p.second;
        if(st[u]) continue;
        st[u] = true;
        
        for(int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[u] + w[i])
            {
                dist[j] = dist[u] + w[i];
                pq.push({dist[j], j});
            }
        }
    }
}

void dfs(int u, int pre, int d)
{
    if(u == 6)
    {
        ans = min(ans, d);
        return;
    }
    
    for(int i = 1; i <= 5; i++)
    {
        if(!st[i])
        {
            st[i] = true;
            dfs(u + 1, i, d + dist[pre][pos[i]]);
            st[i] = false;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    pos[0] = 1;
    for(int i = 1; i <= 5; i++) scanf("%d", &pos[i]);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    for(int i = 0; i < 6; i++)
    {
        dijkstra(pos[i], dist[i]);
    }
    
    for(int i = 1; i <= n; i++) printf("%d ", dist[pos[0]][i]);
    printf("\n");
    
    ans = 0x3f3f3f3f;
    memset(st, 0, sizeof st);
    dfs(1, 0, 0);
    
    printf("%d\n", ans);
    
    return 0;
}
