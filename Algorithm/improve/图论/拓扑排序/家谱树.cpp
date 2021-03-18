#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 110, M = N * N;

int h[N], e[M], ne[M], idx;
int q[N], d[N];
int n;

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
    scanf("%d", &n);
    
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++)
    {
        int a;
        while(scanf("%d", &a) && a)
        {
            add(i, a);
            d[a]++;
        }
    }
    
    topsort();
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
    
    return 0;
}
