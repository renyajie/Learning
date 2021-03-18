#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

const int N = 510;

typedef pair<int,int> PII;

char g[N][N];
int dis[N][N];
int n, m;

int bfs()
{
    memset(dis, 0x3f, sizeof dis);
    deque<PII> q;
    q.push_back({0, 0});
    dis[0][0] = 0;
    
    char s[5] = "\\/\\/";
    int dir[4][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    int idx[4][2] = {{-1, -1}, {-1, 0}, {0, 0}, {0, -1}};
    
    while(q.size())
    {
        auto p = q.front(); q.pop_front();
        int x = p.first, y = p.second;
        if(x == n && y == m) return dis[x][y];
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
            
            int gx = x + idx[i][0], gy = y + idx[i][1];
            if(gx < 0 ||gx >= n || gy < 0 || gy >= m) continue;
            
            int w = g[gx][gy] != s[i];
            if(dis[nx][ny] > dis[x][y] + w)
            {
                dis[nx][ny] = dis[x][y] + w;
                if(w == 0) q.push_front({nx, ny});
                else q.push_back({nx, ny});
            }
            
            
        }
    }
    
    return dis[n][m];
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%s", g[i]);
        
        int ans = bfs();
        if(ans == 0x3f3f3f3f) printf("NO SOLUTION\n");
        else printf("%d\n", ans);
    }
    
    return 0;
}
