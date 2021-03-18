#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 110;

typedef pair<int,int> PII;

int g[N][N];
PII match[N][N];
bool st[N][N];
int n, m, k;

int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
bool find(int x, int y)
{
    for(int i = 0; i < 8; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(g[nx][ny] || st[nx][ny]) continue;
        st[nx][ny] = true;
        PII t = match[nx][ny];
        if(t.first == 0 || find(t.first, t.second))
        {
            match[nx][ny] = {x, y};
            return true;
        }
    }
    
    return false;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        g[a][b] = 1;
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!g[i][j] && (i + j) % 2)
            {
                memset(st, 0, sizeof st); // 记得搜索之前重置
                if(find(i, j)) ans++;
            }
        }
    }
    
    printf("%d\n", n * m - k - ans);
    
    return 0;
}
