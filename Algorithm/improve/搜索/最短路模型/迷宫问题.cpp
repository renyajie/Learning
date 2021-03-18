#include<iostream>
using namespace std;

const int N = 1010, M = N * N;

typedef pair<int,int> PII;

int g[N][N];
bool st[N][N];
PII q[M];
PII pre[N][N];
int n;

int bfs(int sx, int sy)
{
    int hh = 0, tt = -1;
    q[++tt] = {sx, sy};
    st[sx][sy] = true;
    
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while(hh <= tt)
    {
        PII t = q[hh++];
        int x = t.first, y = t.second;
        if(x == 0 && y == 0) break;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(g[nx][ny] || st[nx][ny]) continue;
            st[nx][ny] = true;
            q[++tt] = {nx, ny};
            pre[nx][ny] = {x, y};
        }
    }
    
    return -1;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    
    bfs(n - 1, n - 1);
    
    PII end(0, 0);
    while(true)
    {
        int x = end.first, y = end.second;
        printf("%d %d\n", x, y);
        if(x == n - 1 && y == n - 1) break;
        end = pre[x][y];
    }
    
    return 0;
}

