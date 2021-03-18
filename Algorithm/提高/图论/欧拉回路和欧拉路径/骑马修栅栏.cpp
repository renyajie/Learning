#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510;

int g[N][N];
int d[N];
int ans[1030];
int n = 510, m;
int cnt;

void dfs(int u)
{
    for(int i = 1; i <= n; i++)
    {
        if(g[u][i])
        {
            g[u][i]--, g[i][u]--;
            dfs(i);
        }
    }
    ans[++cnt] = u;
}

int main()
{
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        g[a][b]++, g[b][a]++;
        d[a]++, d[b]++;
    }
    
    int start = 1;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] % 2)
        {
            start = i;
            break;
        }
    }
    
    dfs(start);
    
    //cout << start << endl;
    
    for(int i = cnt; i; i--) printf("%d\n", ans[i]);
    
    return 0;
}
