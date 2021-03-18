#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+10;
typedef long long ll;
int a[N];
int n,p,m;
struct Node
{
    int l,r;
    ll sum,mul,add;
}tr[4*N];

void pushup(int u)
{
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%p;
}

void pushdown(int u)
{
    ll a=tr[u].add,m=tr[u].mul;
    tr[u<<1].sum=(tr[u<<1].sum*m%p+(ll)a*(tr[u<<1].r-tr[u<<1].l+1)%p)%p;
    tr[u<<1|1].sum=(tr[u<<1|1].sum*m%p+(ll)a*(tr[u<<1|1].r-tr[u<<1|1].l+1)%p)%p;
    tr[u<<1].mul=tr[u<<1].mul*m%p,tr[u<<1].add=(tr[u<<1].add*m%p+a)%p;
    tr[u<<1|1].mul=tr[u<<1|1].mul*m%p,tr[u<<1|1].add=(tr[u<<1|1].add*m%p+a)%p;
    tr[u].add=0,tr[u].mul=1;
}

void build(int u,int l,int r)
{
    tr[u]={l,r,0,1,0};
    if(l==r) {tr[u].sum=a[l]; return;}
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int m,int a)
{
    if(tr[u].l>=l&&tr[u].r<=r) 
    {
        tr[u].sum=(tr[u].sum*m%p+(ll)a*(tr[u].r-tr[u].l+1)%p)%p;
        tr[u].mul=tr[u].mul*m%p,tr[u].add=(tr[u].add*m%p+a)%p;
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(l<=mid) modify(u<<1,l,r,m,a); //注意此处保持l,r不变
    if(r>mid) modify(u<<1|1,l,r,m,a);
    pushup(u);
}

ll query(int u,int l,int r)
{
    if(tr[u].l>=l && tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    ll ans=0;
    if(l<=mid) ans=(ans+query(u<<1,l,r))%p; //注意此处保持l,r不变
    if(r>mid) ans=(ans+query(u<<1|1,l,r))%p;
    return ans;
}

int main()
{
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    int t,l,r,c;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&t,&l,&r);
        if(t!=3) scanf("%d",&c);
        if(t==1) modify(1,l,r,c,0);
        else if(t==2) modify(1,l,r,1,c);
        else printf("%lld\n",query(1,l,r));
    }
    return 0;
}
