#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 200010;

typedef long long ll;

int lo[N], gr[N];
int tr[N];
int a[N];
int n;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

ll sum(int x)
{
    ll ans = 0;
    for(int i = x; i; i -= lowbit(i)) ans += tr[i];
    return ans;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    // 正向求解 i 的左侧
    for(int i = 1; i <= n; i++)
    {
        gr[i] = sum(n) - sum(a[i]);
        lo[i] = sum(a[i] - 1);
        //printf("%d[%d]: %d %d\n", i, a[i], gr[i], lo[i]);
        add(a[i], 1);
    }
    
    memset(tr, 0, sizeof tr);
    ll ans1 = 0, ans2 = 0;
    
    // 反向求 i 的右侧，并统计答案
    for(int i = n; i; i--)
    {
        ans1 += gr[i] * (ll)(sum(n) - sum(a[i]));
        ans2 += lo[i] * (ll)(sum(a[i] - 1));
        add(a[i], 1);
    }
    
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}
