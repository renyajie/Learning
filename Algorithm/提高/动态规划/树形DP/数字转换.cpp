#include<iostream>
#include<cstring>
using namespace std;

const int N = 50010, M = 2 * N;

int h[N], e[N], ne[N], idx;
int s[N];
int ans;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int father)
{
    st[u] = true;
    int d1 = 0, d2 = 0;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;
        int dis = dfs(j, u) + 1;
        if(dis > d1) d2 = d1, d1 = dis;
        else if(dis > d2) d2 = dis;
    }
    
    ans = max(ans, d1 + d2);
    return d1;
}

int main()
{
    int n; scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 2; j <= n / i; j++)
        {
            s[j * i] += i;
        }
    }
    
    for(int i = 2; i <= n; i++)
    {
        if(i > s[i])
        {
            add(s[i], i);
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!st[i]) dfs(i, -1);
    }
    
    printf("%d\n", ans);
    
    return 0;
}
