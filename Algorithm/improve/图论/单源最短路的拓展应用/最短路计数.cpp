#include<iostream>
#include<cstring>
using namespace std;

const int N = 100010, M = 400010, mod= 100003;

int h[N], e[M], ne[M], idx;
int dist[N], q[N], cnt[N];
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0, cnt[1] = 1;
    int hh = 0, tt = -1;
    q[++tt] = 1;
    
    while(hh <= tt)
    {
        int t = q[hh++];
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + 1)
            {
                dist[j] = dist[t] + 1;
                q[++tt] = j;
                cnt[j] = cnt[t];
            }
            else if(dist[j] == dist[t] + 1)
            {
                cnt[j] = (cnt[j] + cnt[t]) % mod;
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
        add(a, b), add(b, a);
    }
    
    bfs();
    
    for(int i = 1; i <= n; i++)
    {
        printf("%d\n", cnt[i]);
    }
    
    return 0;
}
