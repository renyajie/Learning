#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010, M = 210010, INF = 0x3f3f3f3f;

int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int q[N];
int n, m, T;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa()
{
    int hh = 0, tt = 0;
    q[tt++] = 0;
    
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0] = 0;
    st[0] = true;
    
    while(hh != tt)
    {
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q[tt++] = j;
                    if(tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    
    if(dist[T] == INF) return -1;
    return dist[T];
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &T) == 3)
    {
        memset(h, -1, sizeof h);
        for(int i = 0; i < m; i++)
        {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        
        int s; scanf("%d", &s);
        for(int i = 0; i < s; i++) 
        {
            int t; scanf("%d", &t);
            add(0, t, 0);
        }
        
        printf("%d\n", spfa());
    }

    
    return 0;
}
