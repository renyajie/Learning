#include<iostream>
using namespace std;

const int N = 1010, M = N * N;

typedef pair<int,int> PII;

PII q[M];
int g[N][N];
bool st[N][N];
int n;

int bfs(int sx, int sy, bool &has_higher, bool &has_lower)
{
    int hh = 0, tt = -1;
    q[++tt] = {sx, sy};
    st[sx][sy] = true;
    
    int num = g[sx][sy];
    while(hh <= tt)
    {
        PII t = q[hh++];
        int x = t.first, y = t.second;
        for(int nx = x - 1; nx <= x + 1; nx++)
        {
            for(int ny = y - 1; ny <= y + 1; ny++)
            {
                if(nx == x && ny == y) continue;
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(g[nx][ny] != num)
                {
                    if(g[nx][ny] > num) has_higher = true;
                    else has_lower = true;
                }
                else if(!st[nx][ny]) 
                {
                    q[++tt] = {nx, ny};
                    st[nx][ny] = true;
                }
            }
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
    
    int high = 0, low = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!st[i][j])
            {
                bool has_higher = false, has_lower = false;
                bfs(i, j, has_higher, has_lower);
                if(!has_higher) high++;
                if(!has_lower) low++;
            }
        }
    }
    
    printf("%d %d\n", high, low);
    
    return 0;
}
