#include<iostream>
#include<cstring>
using namespace std;

const int N = 110, M = 20010, INF = 0x3f3f3f3f;

typedef long long ll;

int dist[N][N], pre[N][N]; // pre保留初始距离
int cnt;
int path[N];
int p[N][N]; // 保留转移点
int n, m;

void dfs(int i, int j)
{
    if(!p[i][j]) return;
    
    int k = p[i][j];
    dfs(i, k);
    path[cnt++] = k;
    dfs(k, j);
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(pre, 0x3f, sizeof pre);
    for(int i = 1; i <= n; i++) pre[i][i] = 0;
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        pre[a][b] = pre[b][a] = min(pre[a][b], c);
    }
    
    memcpy(dist, pre, sizeof pre);
    int ans = 0x3f3f3f3f;
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i < k; i++)
        {
            for(int j = i + 1; j < k; j++)
            {
                if((ll)pre[i][k] + pre[k][j] + dist[j][i] < ans) // 注意K是新的点，用原来最开始的距离，而不是前k-1次计算后的距离
                {
                    ans = pre[i][k] + pre[k][j] + dist[j][i];
                    
                    cnt = 0;
                    path[cnt++] = k;
                    path[cnt++] = i;
                    dfs(i, j);
                    path[cnt++] = j;
                }
            }
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
    
    if(ans == INF) printf("No solution.\n");
    else
    {
        for(int i = 0; i < cnt; i++) printf("%d ", path[i]);
        printf("\n");
    }
    
    return 0;
}
