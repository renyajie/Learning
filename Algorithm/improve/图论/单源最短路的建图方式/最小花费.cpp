#include<iostream>
using namespace std;

const int N = 2010;

double g[N][N];
double dist[N];
bool st[N];
int n, m, s, t;

void dijkstra()
{
    dist[s] = 1;
    for(int i = 0; i < n - 1; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[t] < dist[j]))
            {
                t = j;
            }
        }
        
        st[t] = true;
        for(int j = 1; j <= n; j++)
        {
            dist[j] = max(dist[j], dist[t] * g[t][j]);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = max(g[a][b], (double)(100 - c) / 100);
    }
    
    scanf("%d%d",&s, &t);
    
    dijkstra();
    
    printf("%.8lf\n", 100.0 / dist[t]);
    
    return 0;
}
