// 单点修改，区间查询
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 10;

int m, p;

struct Node
{
    int l, r, v;
}tr[N * 4];

void pushup(int u)
{
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r)
{
    if(l == r) tr[u] = {l, r, 0};
    else
    {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r); // 左区间[l, mid]，右区间[mid+1, r]
        pushup(u);
    }
}

void modify(int u, int x, int c)
{
    if(tr[u].l == x && tr[u].r == x) tr[u].v = c;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, c);
        else if(x > mid) modify(u << 1 | 1, x, c);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].v;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid) return query(u << 1, l, r);
        else if(l > mid) return query(u << 1 | 1, l, r);
        else return max(query(u << 1, l, mid), query(u << 1 | 1, mid + 1, r));
    }
}

int main()
{
    scanf("%d%d", &m, &p);
    
    build(1, 1, m);
    
    char op[3];
    int t, a = 0;
    int len = 0;
    for(int i = 1; i <= m; i++)
    {
        scanf("%s%d", op, &t);
        if(op[0] == 'A') modify(1, ++len, (t + a) % p);
        else a = query(1, len - t + 1, len), printf("%d\n", a);
    }
    
    return 0;
}
