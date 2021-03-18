#include<iostream>
#include<cstring>
using namespace std;

const int N = 30;

char g[N][N];
bool st[N][N];
int n, m;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dfs(int x, int y)
{
    int cnt = 1;
    st[x][y] = true;
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(st[nx][ny]) continue;
        if(g[nx][ny] != '.') continue;
        cnt += dfs(nx, ny);
    }
    
    return cnt;
}

int main()
{
    while(scanf("%d%d", &m, &n) == 2 && (n || m))
    {
        for(int i = 0; i < n; i++) scanf("%s", g[i]);
        
        memset(st, false, sizeof st);
        int sx, sy;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(g[i][j] == '@')
                {
                    sx = i, sy = j;
                }
            }
        }
        
        printf("%d\n", dfs(sx, sy));
    }
    
    return 0;
}
