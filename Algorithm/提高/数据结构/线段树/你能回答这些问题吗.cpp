#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 5e5 + 10;

typedef long long ll;

int n, m;
ll a[N];

struct Node
{
    int l, r;
    ll tmax, sum, lmax, rmax;
}tr[4 * N];

void push_up(Node &u, Node &l, Node &r)
{
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax, l.sum + r.lmax);
    u.rmax = max(r.rmax, r.sum + l.rmax);
}

void push_up(int u)
{
    push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if(l == r) tr[u] = {l, r, a[l], a[l], a[l], a[l]};
    else
    {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

void modify(int u, int x, int c)
{
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x, x, c, c, c, c};
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, c);
        else if(x > mid) modify(u << 1 | 1, x, c);
        push_up(u);
    }
}

Node query(int u, int l, int r)
{
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
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    build(1, 1, n);
    
    int t, x, y;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &t, &x, &y);
        if(t == 1) 
        {
            if(x > y) swap(x, y);
            printf("%d\n", query(1, x, y).tmax);
        }
        else modify(1, x, y);
    }
    return 0;
}
