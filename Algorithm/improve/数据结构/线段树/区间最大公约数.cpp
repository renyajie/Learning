#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 5e5 + 10;

typedef long long ll;

struct Node
{
    int l, r;
    ll sum, d;
}tr[4 * N];

ll a[N];
int n, m;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

void push_up(Node &u, Node &l, Node &r)
{
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}

void push_up(int u)
{
    push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if(l == r) 
    {
        ll x = a[r] - a[r - 1];
        tr[u] = {l, r, x, x};
    }
    else
    {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

void modify(int u, int x, ll c)
{
    //printf("%d->[%d, %d] %d %lld\n", u, tr[u].l, tr[u].r, x, c);
    if(tr[u].l == x && tr[u].r == x) 
    {
        tr[u] = {x, x, tr[u].sum + c, tr[u].sum + c}; // 注意这里是加上一个数，不要想当然的写成c
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, c);
        else modify(u << 1 | 1, x, c);
        push_up(u);
    }
}

Node query(int u, int l, int r)
{
    if(l > r) return {0, 0, 0, 0};
    if(tr[u].l >= l && tr[u].r <= r) return tr[u];
    else 
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid) return query(u << 1, l, r);
        else if(l > mid) return query(u << 1 | 1, l, r);
        else
        {
            Node ln = query(u << 1, l, mid);
            Node rn = query(u << 1 | 1, mid + 1, r);
            Node res;
            push_up(res, ln, rn);
            return res;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld\n", &a[i]);
    build(1, 1, n);
    
    char op[3];
    int l, r;
    ll d;
    for(int i = 0; i < m; i++)
    {
        scanf("%s%d%d", op, &l, &r);
        if(op[0] == 'Q')
        {
            printf("%lld\n", abs(gcd(query(1, 1, l).sum, query(1, l + 1, r).d)));
        }
        else
        {
            scanf("%lld", &d);
            modify(1, l, d);
            if(r + 1 <= n) modify(1, r + 1, -d);
        }
    }
    return 0;
}
