#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 110;

int g[N][N];
int dist[N];
bool st[N];
int n;

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
            {
                t = j;
            }
        }
        
        if(i && dist[t] == 0x3f3f3f3f) return -1;
        ans += dist[t];
        st[t] = true;
        
        for(int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    
    return ans;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    
    printf("%d\n", prim());
    
    return 0;
}
