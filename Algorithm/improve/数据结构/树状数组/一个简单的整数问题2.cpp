/*
区间修改，区间查询
d1
d1 d2
d1 d2 d3
...
d1 d2 d3 .. dx
==
区间和：(d1+..dx)*(x+1) - (1*d1+2*d2+...+x*dx)
因此维护 两个树状数组 di，和i * di
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010;

typedef long long ll;

ll tr1[N], tr2[N];
int a[N];
int n, m;

int lowbit(int x)
{
    return x & -x;
}

void add(ll tr[], int x, ll c)
{
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

ll sum(ll tr[], int x)
{
    ll ans = 0;
    for(int i = x; i; i -= lowbit(i)) ans += tr[i];
    return ans;
}

ll get_sum(int x)
{
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) add(tr1, i, a[i] - a[i - 1]), add(tr2, i, i * (ll)(a[i] - a[i - 1]));
    for(int i = 0; i < m; i++)
    {
        char s[3]; int a, b, c;
        scanf("%s%d%d", s, &a, &b);
        //printf("%d: %s\n", i, s);
        if(s[0] == 'Q') printf("%lld\n", get_sum(b) - get_sum(a - 1));
        else
        {
            scanf("%d", &c);
            add(tr1, a, c), add(tr1, b + 1, -c), add(tr2, a, (ll)a * c), add(tr2, b + 1, ll(b + 1) * -c);
        }
    }
    return 0;
}
