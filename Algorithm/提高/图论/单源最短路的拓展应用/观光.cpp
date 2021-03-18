#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1010, M = 10010, INF = 0x3f3f3f3f;

struct pos
{
    int ver, distance, type;
    bool operator> (const pos &p) const
    {
        return distance > p.distance;
    }
};

int h[N], e[M], ne[M], w[M], idx;
int dist[N][2], cnt[N][2];
bool st[N][2];
int n, m, S, F, T;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    dist[S][0] = 0, cnt[S][0] = 1; // 0最小距离，1次小距离
    priority_queue<pos, vector<pos>, greater<pos>> pq;
    pq.push({S, 0, 0});
    
    while(pq.size())
    {
        pos t = pq.top(); pq.pop();
        int ver = t.ver, distance = t.distance, type = t.type;
        if(st[ver][type]) continue;
        st[ver][type] = true;
        
        for(int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j][0] > distance + w[i])
            {
                dist[j][1] = dist[j][0], cnt[j][1] = cnt[j][0];
                pq.push({j, dist[j][1], 1});
                dist[j][0] = distance + w[i], cnt[j][0] = cnt[ver][type];
                pq.push({j, dist[j][0], 0});
            }
            else if(dist[j][0] == distance + w[i])
            {
                cnt[j][0] += cnt[ver][type];
            }
            else if(dist[j][1] > distance + w[i])
            {
                dist[j][1] = distance + w[i], cnt[j][1] = cnt[ver][type];
                pq.push({j, dist[j][1], 1});
            }
            else if(dist[j][1] == distance + w[i])
            {
                cnt[j][1] += cnt[ver][type];
            }
        }
    }
    
    int ans = cnt[F][0];
    if(dist[F][1] == dist[F][0] + 1) ans += cnt[F][1];
    return ans;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        
        memset(h, -1, sizeof h);
        memset(st, 0, sizeof st);
        for(int i = 0; i < m; i++)
        {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        
        scanf("%d%d", &S, &F);
        
        printf("%d\n", dijkstra());
    }
    
    return 0;
}
