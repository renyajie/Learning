#include<iostream>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;

const int N = 30010, M = 30010;

int h[N], e[N], ne[N], idx;
int q[N], d[N];
bitset<N> dp[N];
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort()
{
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; i++)
    {
        if(!d[i])
        {
            q[++tt] = i;
        }
    }
    
    while(hh <= tt)
    {
        int t = q[hh++];
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(--d[j] == 0)
            {
                q[++tt] = j;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }
    
    topsort();
    
    for(int i = n - 1; i >= 0; i--)
    {
        int t = q[i]; // 记得从拓扑序中取出来
        dp[t][t] = 1;
        for(int j = h[t]; ~j; j = ne[j])
        {
            int k = e[j];
            dp[t] |= dp[k];
        }
    }
    
    for(int i = 1; i <= n; i++) printf("%d\n", dp[i].count());
    return 0;
}
