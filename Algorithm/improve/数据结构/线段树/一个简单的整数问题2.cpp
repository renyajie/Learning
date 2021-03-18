#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

struct Node
{
    int l, r;
    ll sum, add;
}tr[N * 4];

int n, m;
ll a[N];

void push_up(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void push_down(int u)
{
    if(tr[u].add)
    {
        tr[u << 1].sum += (ll)(tr[u << 1].r - tr[u << 1].l + 1) * tr[u].add; // 传递下层并标记下层
        tr[u << 1].add += tr[u].add;
        tr[u << 1 | 1].sum += (ll)(tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].add;
        tr[u << 1 | 1].add += tr[u].add;
        tr[u].add = 0;
    }
}

void build(int u, int l, int r)
{
    if(l == r) tr[u] = {l, r, a[l], 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

void modify(int u, int l, int r, int c)
{
    if(tr[u].l >= l && tr[u].r <= r) 
    {
        tr[u].sum += (ll)(tr[u].r - tr[u].l + 1) * c;
        tr[u].add += c; // 此处是继续累计，而不是直接赋值
    }
    else
    {
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, c);
        if(r > mid) modify(u << 1 | 1, l, r, c);
        push_up(u);
    }
}

ll query(int u, int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll res = 0;
    if(l <= mid) res = query(u << 1, l, r);
    if(r > mid) res += query(u << 1 | 1, l, r);
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    
    build(1, 1, n);
    
    char op[3];
    int l, r, d;
    for(int i = 0; i < m; i++)
    {
        scanf("%s%d%d", op, &l, &r);
        if(op[0] == 'Q') printf("%lld\n", query(1, l, r));
        else
        {
            scanf("%d", &d);
            modify(1, l, r, d);
        }
    }
    
    return 0;
}
