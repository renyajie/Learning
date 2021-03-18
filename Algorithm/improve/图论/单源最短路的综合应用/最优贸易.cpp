// 枚举中间点k，dmin[k]表示1-k买入的最小值，dmax[k]表示k-n卖出的最大值
// 存在环，不能用动态规划，用最短路，其次出堆元素后面还可能被更新，所以用dijkstra

#include<iostream>
#include<cstring>
using namespace std;

const int N = 100010, M = 2000010;

int h[N], rh[N], e[M], ne[M], idx;
int dmin[N], dmax[N];
int q[N];
bool st[N];
int n, m;
int price[N];

void add(int h[], int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int h[], int dist[], int start, bool flag)
{
    memset(st, 0, sizeof st);
    int hh = 0, tt = 0;
    dist[start] = price[start];
    q[tt++] = start;
    st[start] = true;
    
    
    while(hh != tt)
    {
        int u = q[hh++];
        if(hh == N) hh = 0;
        st[u] = false;
        
        for(int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if(flag && dist[j] > min(price[j], dist[u]) || !flag && dist[j] < max(price[j], dist[u]))
            {
                if(flag) dist[j] = min(price[j], dist[u]);
                else dist[j] = max(price[j], dist[u]);
                
                if(!st[j])
                {
                    q[tt++] = j;
                    if(tt == N) tt = 0;
                    st[j] == true;
                }
            }
            
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &price[i]);
    
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(h, a, b), add(rh, b, a);
        if(c == 2) add(h, b, a), add(rh, a, b);
    }
    
    memset(dmax, 0, sizeof dmax);
    memset(dmin, 0x3f, sizeof dmin);
    
    spfa(h, dmin, 1, true);
    spfa(rh, dmax, n, false);
    
    int ans = 0;
    for(int i = 1; i <= n; i++) 
    {
        ans = max(ans, dmax[i] - dmin[i]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}
