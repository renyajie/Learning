#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;

int g[N][N];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; i++) g[i][i] = 0;
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, g[1][i]);
    }
    
    if(ans == 0x3f3f3f3f) printf("-1\n");
    else printf("%d\n", ans);
    
    return 0;
}
