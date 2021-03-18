#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 20010, M = 200010;

int h[N], e[M], ne[M], w[M], idx;
int color[N];
int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c, int x)
{
    color[u] = c;
    for(int i = h[u]; ~i; i = ne[i])
    {
        if(w[i] <= x) continue;
        int j = e[i];
        if(!color[j] && !dfs(j, 3 - c, x)) return false;
        else if(color[j] == color[u]) return false;
    }
    return true;
}

bool check(int x)
{
    memset(color, 0, sizeof color);
    for(int i = 1; i <= n; i++)
    {
        if(!color[i]) 
        {
            if(!dfs(i, 1, x)) return false;
        }
    }
    
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    int l = 0, r = 1e9;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    
    printf("%d\n", l);
    
    return 0;
}
