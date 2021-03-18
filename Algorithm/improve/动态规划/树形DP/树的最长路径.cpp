#include<iostream>
#include<cstring>
using namespace std;

const int N = 10010, M = 2 * N;

int h[N], e[M], ne[M], w[M], idx;
int ans;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int father)
{
    int d1 = 0, d2 = 0;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;
        int dis = dfs(j, u) + w[i];
        if(dis > d1) 
        {
            d2 = d1, d1 = dis;
        }
        else if(dis > d2) d2 = dis;
    }
    
    ans = max(ans, d1 + d2);
    return d1;
}

int main()
{
    int n; scanf("%d", &n);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    dfs(1, -1);
    
    printf("%d\n", ans);
    
    return 0;
}
