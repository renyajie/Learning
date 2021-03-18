#include<iostream>
using namespace std;

const int N = 160, M = N * N;

typedef pair<int,int> PII;

char g[N][N];
bool st[N][N];
PII q[M];
int n, m;
int dis[N][N];

int bfs(int sx, int sy)
{
    int hh = 0, tt = -1;
    q[++tt] = {sx, sy};
    st[sx][sy] = true;
    dis[sx][sy] = 0;
    
    int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    
    while(hh <= tt)
    {
        PII t = q[hh++];
        int x = t.first, y = t.second;
        if(g[x][y] == 'H') return dis[x][y];
        for(int i = 0; i < 8; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(g[nx][ny] == '*' || st[nx][ny]) continue;
            st[nx][ny] = true;
            q[++tt] = {nx, ny};
            dis[nx][ny] = dis[x][y] + 1;
        }
        
    }
    
    return -1;
}

int main()
{
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++) scanf("%s", g[i]);
    
    int sx = 0, sy = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(g[i][j] == 'K')
            {
                sx = i;
                sy = j;
            }
        }
    }
    
    printf("%d\n", bfs(sx, sy));
    
    return 0;
}
