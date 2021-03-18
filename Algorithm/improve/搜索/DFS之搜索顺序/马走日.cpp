#include<iostream>
#include<cstring>
using namespace std;

const int N = 16;

bool st[N][N];

int n, m, x, y;
int ans;

int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

void dfs(int px, int py, int cnt)
{
    if(cnt == n * m) 
    {
        ans++;
        return;
    }
    
    st[px][py] = true;
    for(int i = 0; i < 8; i++)
    {
        int nx = px + dir[i][0], ny = py + dir[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(st[nx][ny]) continue;
        dfs(nx, ny, cnt + 1);
    }
    st[px][py] = false;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d%d", &n, &m, &x, &y);
        ans = 0;
        
        dfs(x, y, 1);
        printf("%d\n", ans);
    }
    
    return 0;
}
