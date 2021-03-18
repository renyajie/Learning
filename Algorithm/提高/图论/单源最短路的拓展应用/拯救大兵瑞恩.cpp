// 1. if(!keys[x][y])  d[x][y][state | key] = min(d[x][y][state | key])
// 2. if(!g[x][y][a][b] || astate >> g[x][y][a][b] - 1 & 1) d[a][b][state] = min(d[a][b][state], d[x][y][state] + 1)

// 空地 -- 0
// 门 -- 对应的类型

#include<iostream>
#include<cstring>
#include<deque>
using namespace std;

const int N = 11, M = 400, P = 1 << 11;

typedef pair<int,int> PII;

int h[M], e[M], ne[M], idx;
int keys[M];
int g[M][M];
int n, m, p;
int dist[M][P];
int st[M][P];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void build_empty()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int x = i + dir[k][0], y = j + dir[k][1];
                if(!x || x > n || !y || y > m) continue;
                
                int a = (i - 1) * m + j, b = (x - 1) * m + y;
                if(g[a][b] == 0) 
                {
                    add(a, b);
                }
            }
        }
    }
}

int bfs()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;
    deque<PII> q;
    q.push_back({0, 1});
    
    while(q.size())
    {
        PII t = q.front(); q.pop_front();
        int ver = t.second, state = t.first;
        
        //printf("ver:%d state:%d\n", ver, state);
        
        if(ver == n * m) return dist[ver][state];
        if(st[ver][state]) continue;
        st[ver][state] = true;
        
        if(keys[ver])
        {
            //printf("has key!\n");
            if(dist[ver][state | keys[ver]] > dist[ver][state])
            {
                dist[ver][state | keys[ver]] = dist[ver][state];
                q.push_front({state | keys[ver], ver});
                //printf("add new state\n");
            }
            //state |= keys[ver];
        }
            
        for(int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            //printf("check %d\n", j);
            
            
            if(!g[ver][j] || state >> g[ver][j] - 1 & 1)
            {
                //printf("can in %d->%d\n", ver, j);
                if(dist[j][state] > dist[ver][state] + 1)
                {
                    dist[j][state] = dist[ver][state] + 1;
                    q.push_back({state, j});
                    //printf("add new point %d\n", j);
                }
                
            }
        }
    }
    
    return -1;
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    
    memset(h, -1, sizeof h);
    
    int k; scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2, type; scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &type);
        int a = (x1 - 1) * m + y1, b = (x2 - 1) * m + y2;
        
        if(type) 
        {
            g[a][b] = g[b][a] = type;
            add(a, b), add(b, a);
        }
        else
        {
            g[a][b] = g[b][a] = -1;
        }
    }
    
    build_empty();
    
    int s; scanf("%d", &s);
    for(int i = 0; i < s; i++)
    {
        int x, y, q; scanf("%d%d%d", &x, &y, &q);
        keys[(x - 1) * m + y] |= 1 << (q - 1);
    }
    
    //for(int i = h[10]; ~i; i = ne[i]) printf("%d ", e[i]);
    //printf("\n");
    //printf("%d %d\n", g[10][14], dist[14][2]);
    
    printf("%d\n", bfs());
    
    return 0;
}
