// 相当于求路径上第K+1条最大的边的长度的最小值
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1010, M = 20010;

int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
int n, m, K;

typedef pair<int,int> PII;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(int x)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 1});
    
    while(pq.size())
    {
        PII p = pq.top(); pq.pop();
        int u = p.second;
        if(st[u]) continue;
        st[u] = true;
        
        for(int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            int d = w[i] > x ? 1 : 0;
            if(dist[j] > dist[u] + d)
            {
                dist[j] = dist[u] + d;
                pq.push({dist[j], j});
            }
        }
    }
    
    return dist[n] <= K;
}

int main()
{
    scanf("%d%d%d", &n, &m, &K);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    int l = 0, r = 1e6 + 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    
    if(l == 1e6 + 1) printf("-1\n");
    else printf("%d\n", l);
    
    return 0;
}
