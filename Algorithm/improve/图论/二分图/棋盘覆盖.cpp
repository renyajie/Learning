#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;

const int N = 110;

PII match[N][N];
bool st[N][N];
bool g[N][N];
int n, k;


int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool find(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
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
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        g[a][b] = true;
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(g[i][j] || (i + j) % 2) continue;
            memset(st, 0, sizeof st);
            if(find(i, j)) ans++;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
