#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1010, M = 5010;

int h[N], e[M], ne[M], w[M], idx;
int f[N];
double dist[N];
int cnt[N], q[N];
bool st[N];
int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(double x)
{
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    memset(dist, 0, sizeof dist);
    
    int hh = 0, tt = 0;
    for(int i = 1; i <= n; i++)
    {
        q[tt++] = i;
        st[i] = true;
    }
    
    while(hh != tt)
    {
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] < dist[t] + f[t] - x * w[i])
            {
                dist[j] = dist[t] + f[t] - x * w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                
                if(!st[j])
                {
                    q[tt++] = j;
                    if(tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &f[i]);
    
    memset(h, -1, sizeof h);
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    double l = 0, r = 1000;
    while(r - l > 1e-4)
    {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    
    printf("%.2lf\n", l);
    
    return 0;
}
