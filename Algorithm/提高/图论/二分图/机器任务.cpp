#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 110;

int d[N][N];
int match[N];
bool st[N];
int n, m, k;

bool find(int u)
{
    for(int i = 1; i < m; i++)
    {
        if(!d[u][i]) continue;
        if(st[i]) continue;
        st[i] = true;
        int t = match[i];
        if(t == 0 || find(t))
        {
            match[i] = u;
            return true;
        }
    }
    
    return false;
}

int main()
{
    while(scanf("%d", &n) && n)
    {
        scanf("%d%d", &m, &k);
        memset(d, 0, sizeof d);
        memset(match, 0, sizeof match);
        for(int i = 0; i < k; i++)
        {
            int t, a, b; scanf("%d%d%d", &t, &a, &b);
            if(a == 0 || b == 0) continue;
            d[a][b] = 1;
        }
        
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            memset(st, 0, sizeof st);
            if(find(i)) ans++;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
