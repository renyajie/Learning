#include<iostream>
using namespace std;

const int N = 1010, M = N * N;

typedef pair<int,int> PII;

char g[N][N];
bool st[N][N];
PII q[M];
int n, m;

int bfs(int sx, int sy)
{
    int hh = 0, tt = -1;
    q[++tt] = {sx, sy};
    st[sx][sy] = true;
    
    while(hh <= tt)
    {
        PII t = q[hh++];
        int x = t.first, y = t.second;
        for(int i = x - 1; i <= x + 1; i++)
        {
            for(int j = y - 1; j <= y + 1; j++)
            {
                if(i == x && j == y) continue;
                if(i < 0 || i >= n || j < 0 || j >= m) continue;
                if(g[i][j] == '.' || st[i][j]) continue;
                st[i][j] = true;
                q[++tt] = {i, j};
            }
        }
    }
    
    return -1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%s", g[i]);
    
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(g[i][j] == 'W' && !st[i][j]) 
            {
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
