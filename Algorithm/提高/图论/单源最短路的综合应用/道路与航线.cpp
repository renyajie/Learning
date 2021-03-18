// 标号，拓扑排序后，对每一团做dijkstra
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int N = 25010, M = 100000 * 2 + 10, INF = 0x3f3f3f3f;

typedef pair<int,int> PII;

int T, R, P, S;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int id[N];
int id_cnt;
int ind[N];
queue<int> q;
vector<int> idset[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int k)
{
    id[u] = k;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!id[j]) dfs(j, k);
    }
}

void dijkstra(int u)
{
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    for(auto i : idset[u])
    {
        pq.push({dist[i], i});
    }
    
    while(pq.size())
    {
        PII p = pq.top(); pq.pop();
        int ver = p.second;
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                if(id[j] == id[ver]) pq.push({dist[j], j}); // 当不在一个团，存在负权，不能加入
            }
            if(id[j] != id[ver] && --ind[id[j]] == 0) q.push(id[j]);
        }
    }
}

void topsort()
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;
    
    for(int i = 1; i <= id_cnt; i++)
    {
        if(ind[i] == 0) q.push(i);
    }
    
    while(q.size())
    {
        int p = q.front(); q.pop();
        dijkstra(p);
    }
}

int main()
{
    scanf("%d%d%d%d", &T, &R, &P, &S);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < R; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    for(int i = 1; i <= T; i++)
    {
        if(!id[i]) 
        {
            dfs(i, ++id_cnt);
        }
    }
    
    for(int i = 1; i <= T; i++) 
    {
        idset[id[i]].push_back(i);
    }
    
    for(int i = 0; i < P; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        ind[id[b]]++;
    }
    
    topsort();
    
    for(int i = 1; i <= T; i++)
    {
        if(dist[i] > INF / 2) printf("NO PATH\n"); // 有负权边这么写 INF / 2
        else printf("%d\n", dist[i]);
    }
}
