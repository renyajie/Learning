#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;

const int N = 510;

int g[N][N];
int dist[N];
int stop[N * 2];
int q[N];
int m, n;

void bfs()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int hh = 0, tt = -1;
    q[++tt] = 1;
    
    while(hh <= tt)
    {
        int p = q[hh++];
        
        for(int i = 1; i <= n; i++)
        {
            if(g[p][i] && dist[i] > dist[p] + 1)
            {
                dist[i] = dist[p] + 1;
                if(i == n) return;
                q[++tt] = i;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &m, &n);
    
    string line;
    getline(cin, line); // 注意先得处理一行
    for(int k = 0; k < m; k++)
    {
        getline(cin, line);
        stringstream ss(line);
        int cnt = 0, p;
        while(ss >> p)
        {
            stop[cnt++] = p;
        }
        for(int i = 0; i < cnt; i++)
        {
            for(int j = i + 1; j < cnt; j++)
            {
                g[stop[i]][stop[j]] = 1;
            }
        }
    }
    
    bfs();
    
    if(dist[n] == 0x3f3f3f3f) printf("NO\n");
    else printf("%d\n", max(dist[n] - 1, 0));
    
    return 0;
}
