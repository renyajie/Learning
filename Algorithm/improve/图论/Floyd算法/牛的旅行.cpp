#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

typedef pair<double,double> PDD;

const int N = 160, M = 310;
const double INF = 1e20;

char g[N][N];
double dist[N][N];
double dmax[N];
PDD pos[N];
int n;

double get(int a, int b)
{
    double x = pos[a].first - pos[b].first;
    double y = pos[a].second - pos[b].second;
    return sqrt(x * x + y * y);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lf%lf", &pos[i].first, &pos[i].second);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", g[i] + 1); // 下标都从1开始，从这种写法从下标1开始输入字符
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            if(i == j) dist[i][j] = 0;
            else if(g[i][j] == '1') dist[i][j] = get(i, j);
        }
    }
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    double ans1 = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dist[i][j] > INF / 2) continue;
            dmax[i] = max(dmax[i], dist[i][j]);
        }
    }
    
    for(int i = 1; i <= n; i++) ans1 = max(ans1, dmax[i]);
    
    double ans2 = INF;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dist[i][j] < INF / 2) continue;
            ans2 = min(ans2, get(i, j) + dmax[i] + dmax[j]);
        }
    }
    
    printf("%.6lf\n", max(ans1, ans2));
    
    return 0;
}
