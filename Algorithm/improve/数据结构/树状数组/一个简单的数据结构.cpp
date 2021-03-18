#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010;

typedef long long ll;

ll a[N], tr[N];
int n, m;

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

// 区间加，单点查：改为差分数组即可，转化为正常的树状数组

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++) add(i, a[i] - a[i - 1]);
    for(int i = 0; i < m; i++)
    {
        char s[3]; int a, b, c;
        scanf("%s%d", s, &a);
        if(s[0] == 'Q') printf("%lld\n", sum(a));
        else
        {
            scanf("%d%d", &b, &c);
            add(a, c), add(b + 1, -c);
        }
    }
    return 0;
}
