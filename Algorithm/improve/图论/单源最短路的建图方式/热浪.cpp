#include<iostream>
#include<cstring>
using namespace std;

const int N = 3000, M = 6210 * 2;

int h[N], e[M], w[M], ne[M], idx;
int n, m, s, t;
int dist[N], q[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    st[s] = true;
    
    int hh = 0, tt = 0;
    q[tt++] = s;
    
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
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    spfa();
    
    printf("%d\n", dist[t]);
    
    return 0;
}
