#include<iostream>
using namespace std;

const int N = 60, M = N * N;

typedef pair<int,int> PII;

int g[N][N];
PII q[M];
bool st[N][N];
int n, m;

int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int bfs(int sx, int sy)
{
    int hh = 0, tt = -1;
    q[++tt] = {sx, sy};
    st[sx][sy] = true;
    
    int cnt = 0;
    while(hh <= tt)
    {
        cnt++;
        PII t = q[hh++];
        int x = t.first, y = t.second;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if((g[x][y] >> i & 1) || st[nx][ny]) continue;
            st[nx][ny] = true;
            q[++tt] = {nx, ny};
        }
    }
    
    return cnt;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    
    int cnt = 0, area = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!st[i][j])
            {
                area = max(area, bfs(i, j));
                cnt++;
            }
        }
    }
    
    printf("%d\n%d\n", cnt, area);
    
    return 0;
}
