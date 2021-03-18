#include<iostream>
using namespace std;

const int N=4e4+10,INF=0x3f3f3f3f;

struct Node
{
    int l,r,key,w,cnt,size;
}tr[N];
int root,idx,n;

int get_node(int x)
{
    tr[++idx].key=x,tr[idx].w=rand();
    tr[idx].cnt=tr[idx].size=1;
    return idx;
}

void pushup(int u)
{
    tr[u].size=tr[tr[u].l].size+tr[tr[u].r].size+tr[u].cnt;
}

void zag(int &p)
{
    int q=tr[p].r;
    tr[p].r=tr[q].l,tr[q].l=p,p=q;
    pushup(tr[p].l),pushup(p);
}

void zig(int &p)
{
    int q=tr[p].l;
    tr[p].l=tr[q].r,tr[q].r=p,p=q;
    pushup(tr[p].r),pushup(p);
}

void build()
{
    get_node(-INF),get_node(INF);
    root=1,tr[1].r=2;
    if(tr[1].w<tr[2].w) zag(root);
    pushup(root);
}

void insert(int &p,int x)
{
    if(!p) p=get_node(x);
    else if(tr[p].key==x) tr[p].cnt++;
    else if(tr[p].key<x)
    {
        insert(tr[p].r,x);
        if(tr[tr[p].r].w>tr[p].w) zag(p);
    }
    else 
    {
        insert(tr[p].l,x);
        if(tr[tr[p].l].w>tr[p].w) zig(p);
    }
    pushup(p);
}

int get_pre(int p,int x) //返回小于等于x的最大数
{
    if(!p) return -INF;
    if(tr[p].key>x) return get_pre(tr[p].l,x);
    return max(tr[p].key,get_pre(tr[p].r,x));
}

int get_next(int p,int x) //返回大于等于x的最小数
{
    if(!p) return INF;
    if(tr[p].key<x) return get_next(tr[p].r,x);
    return min(tr[p].key,get_next(tr[p].l,x));
}

int main()
{
    build();
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int t; scanf("%d",&t);
        int a=get_pre(root,t),b=get_next(root,t);
        if(i) ans+=min(abs(a-t),abs(b-t));
        else ans+=t;
        insert(root,t);
    }
    printf("%d\n",ans);
    return 0;
}
