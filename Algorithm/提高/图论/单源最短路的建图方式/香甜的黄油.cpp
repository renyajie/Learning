#include<iostream>
#include<cstring>
using namespace std;

const int N = 810, M = 1450 * 2 + 10, P = 510;

int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int q[N];
bool st[N];
int id[N];

int n, p, m;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa(int s)
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    int hh = 0, tt = 0;
    q[tt++] = s;
    st[s] = true;
    
    while(hh != tt)
    {
        int p = q[hh++];
        if(hh == N) hh = 0;
        
        st[p] = false;
        for(int i = h[p]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[p] + w[i])
            {
                dist[j] = dist[p] + w[i];
                if(!st[j])
                {
                    q[tt++] = j;
                    if(tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(dist[id[i]] == 0x3f3f3f3f) return 0x3f3f3f3f;
        ans += dist[id[i]];
    }
    
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &p, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &id[i]);
    }
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    int ans = 0x3f3f3f3f;
    for(int i = 1; i <= p; i++)
    {
        ans = min(ans, spfa(i));
    }
    
    printf("%d\n", ans);
    
    return 0;
}
