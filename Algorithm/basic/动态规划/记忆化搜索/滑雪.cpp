#include<iostream>
#include<cstring>
using namespace std;

const int N = 310;

int g[N][N];
int f[N][N];
int r, c;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int dp(int x, int y)
{
    int &v = f[x][y];
    if(v != -1) return v;
    v = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c && g[x][y] > g[nx][ny])
        {
            v = max(v, dp(nx, ny) + 1);
        }
    }
    return v;
}

int main()
{
    scanf("%d%d", &r, &c);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    
    int res = 0;
    memset(f, -1, sizeof f);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            res = max(res, dp(i, j));
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}
