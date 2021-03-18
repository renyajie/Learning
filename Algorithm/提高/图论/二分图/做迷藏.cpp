// 最小路径重复覆盖

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 210;

bool g[N][N];
int match[N];
bool st[N];
int n, m;

bool find(int u)
{
    for(int i = 1; i <= n; i++)
    {
        if(st[i] || !g[u][i]) continue;
        st[i] = true;
        int t = match[i];
        if(!t || find(t))
        {
            match[i] = u;
            return true;
        }
    }
    
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        g[a][b] = true;
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                g[i][j] |= g[i][k] && g[k][j];
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(st, 0, sizeof st);
        if(find(i)) ans++;
    }
    
    printf("%d\n", n - ans);
    
    return 0;
}
