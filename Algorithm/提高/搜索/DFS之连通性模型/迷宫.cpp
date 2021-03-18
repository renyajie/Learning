#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;

char g[N][N];
bool st[N][N];
int sx, sy, ex, ey;
int n;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y)
{
    if(g[x][y] == '#') return;
    st[x][y] = true;
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(g[nx][ny] == '#' || st[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%s", g[i]);
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        
        memset(st, 0, sizeof st);
        dfs(sx, sy);
        
        if(st[ex][ey]) puts("YES");
        else puts("NO");
    }
    
    return 0;
}
