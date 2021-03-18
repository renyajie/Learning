#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1010, M = N * N, P = 2 * M;

struct Edge
{
    int a, b, w;
}e[P];

int g[N][N];
int p[M];
int n, m, cnt;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void get_edges()
{
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= m; k++)
            {
                int x = j + dir[i][0], y = k + dir[i][1];
                if(!x || x > n || !y || y > m) continue;
                if(g[j][k] < g[x][y]) e[cnt++] = {g[j][k], g[x][y], (i / 2) + 1};
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1, t = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++, t++)
        {
            g[i][j] = t;
        }
    }
    
    for(int i = 1; i <= n * m; i++) p[i] = i;
    
    int x1, y1, x2, y2;
    while(scanf("%d%d%d%d", &x1, &y1, &x2, &y2) == 4)
    {
        int a = g[x1][y1], b = g[x2][y2];
        p[find(a)] = find(b);
    }
    
    get_edges();
    
    int ans = 0;
    for(int i = 0; i < cnt; i++)
    {
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if(a != b)
        {
            p[a] = b;
            ans += w;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
