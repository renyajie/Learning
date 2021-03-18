#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N = 100010, M = 300010;

int h[N], e[M], w[M], ne[M], idx;
ll dist[N];
int cnt[N];
bool st[N];
int q[N];

int n, k;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
    memset(dist, -0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    dist[0] = 0;
    int hh = 0, tt = 0;
    q[tt++] = 0;
    st[0] = true;
    
    while(hh != tt)
    {
        int t = q[--tt];
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] < dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n + 1) return false;
                
                if(!st[j])
                {
                    q[tt++] = j;
                    st[j] = true;
                }
            }
        }
    }
    
    return true;
}

int main()
{
    scanf("%d%d", &n, &k);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < k; i++)
    {
        int x, a, b; scanf("%d%d%d", &x, &a, &b);
        if(x == 1) add(b, a, 0), add(a, b, 0);
        else if(x == 2) add(a, b, 1);
        else if(x == 3) add(b, a, 0);
        else if(x == 4) add(b, a, 1);
        else add(a, b, 0);
    }
    
    for(int i = 1; i <= n; i++)
    {
        add(0, i, 1);
    }
    
    if(!spfa()) puts("-1");
    else
    {
        ll ans = 0;
        for(int i = 1; i <= n; i++) ans += dist[i];
        printf("%lld\n", ans);
    }
    
    return 0;
}
