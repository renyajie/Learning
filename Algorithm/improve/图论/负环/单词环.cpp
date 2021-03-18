// 01数分规划+负环

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 700, M = 500000;

int h[N], e[M], ne[M], w[M], idx;
int cnt[N], q[N];
double dist[N];
bool st[N];
int k;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(double x)
{
    memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    
    int hh = 0, tt = 0;
    for(int i = 0; i < 676; i++)
    {
        q[tt++] = i;
        st[i] = true;
    }
    
    int count = 0;
    while(hh != tt)
    {
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] < dist[t] + w[i] - x)
            {
                dist[j] = dist[t] + w[i] - x;
                cnt[j] = cnt[t] + 1;
                if(++count > 10000) return true;
                if(cnt[j] >= N) return true;
                
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
    while(scanf("%d", &k) && k)
    {
        memset(h, -1, sizeof h);
        char s[1010];
        for(int i = 0; i < k; i++)
        {
            scanf("%s", s);
            if(strlen(s) < 2) continue;
            int a = (s[0] - 'a') * 26 + s[1] - 'a';
            int b = (s[strlen(s) - 2] - 'a') * 26 + s[strlen(s) - 1] - 'a';
            
            //printf("%s\n", s);
            //printf("a: %d, b: %d\n", a, b);
            add(a, b, strlen(s));
        }
        
        if(!check(0)) 
        {
            puts("No solution");
            continue;
        }
        
        double l = 0, r = 1000;
        while(r - l > 1e-4)
        {
            double mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        
        printf("%.2lf\n", l);
    }
    
    return 0;
}
