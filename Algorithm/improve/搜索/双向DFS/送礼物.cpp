#include<iostream>
#include<algorithm>
using namespace std;

const int N = 50;
typedef long long ll;

int a[N];
int b[1 << (N / 2)];
int w, n, k, cnt;
ll ans;

void dfs1(int u, int s)
{
    if(u == k)
    {
        b[cnt++] = s;
        return;
    }
    
    dfs1(u + 1, s);
    if((ll)s + a[u] <= w) dfs1(u + 1, (ll)s + a[u]);
}

void dfs2(int u, int s)
{
    if(u == n)
    {
        int l = 0, r = cnt - 1;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(b[mid] <= w - s) l = mid;
            else r = mid - 1;
        }
        if((ll)b[l] + s <= w) ans = max((ll)b[l] + s, ans);
        return;
    }
    
    dfs2(u + 1, s);
    if((ll)s + a[u] <= w) dfs2(u + 1, (ll)s + a[u]);
}

int main()
{
    scanf("%d%d", &w, &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    k = n >> 1;
    dfs1(0, 0);
    
    sort(b, b + cnt);
    
    dfs2(k, 0);
    
    printf("%lld\n", ans);
    
    return 0;
}
