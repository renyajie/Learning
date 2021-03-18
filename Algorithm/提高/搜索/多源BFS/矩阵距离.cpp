#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010, M = N * N;

typedef pair<int,int> PII;

char g[N][N];
PII q[M];
int dis[N][N];
int n, m;

void bfs()
{
    memset(dis, -1, sizeof dis);
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(g[i][j] == '1')
            {
                q[++tt] = {i, j};
                dis[i][j] = 0;
            }
        }
    }
    
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while(hh <= tt)
    {
        PII t = q[hh++];
        int x = t.first, y = t.second;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dis[nx][ny] != -1) continue;
            dis[nx][ny] = dis[x][y] + 1;
            q[++tt] = {nx, ny};
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%s", g[i]);
    
    bfs();
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
