#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2010, M = 2001000;

int h[N], e[M], ne[M], w[M], idx;
int q[N], d[N];
int dist[N];
bool st[N];
int n, m;


void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void topsort()
{
    int hh = 0, tt = -1;
    for(int i = 1; i <= n + m; i++)
    {
        if(!d[i])
        {
            q[++tt] = i;
            //cout << i << " ";
        }
    }
    //cout << endl;
    
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
        memset(st, 0, sizeof st);
        int cnt; scanf("%d", &cnt);
        
        int start = n, end = 1;
        while(cnt--)
        {
            int t; scanf("%d", &t);
            st[t] = true;
            start = min(start, t);
            end = max(end, t);
        }
        
        int point = n + i + 1;
        for(int j = start; j <= end; j++)
        {
            if(st[j]) add(point, j, 1), d[j]++;
            else add(j, point, 0), d[point]++;
        }
    }
    
    topsort();
    
    for(int i = 1; i <= n; i++) dist[i] = 1;
    
    for(int i = 0; i < n + m; i++) // ÍØÆËÅÅÐò´Ó0¿ªÊ¼
    {
        int k = q[i];
        //cout << k << " ";
        for(int j = h[k]; ~j; j = ne[j])
        {
            int m = e[j];
            dist[m] = max(dist[m], dist[k] + w[j]);
        }
    }
    
    //cout << endl;
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
    }
    
    printf("%d\n", ans);

    return 0;
}
