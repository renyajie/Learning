#include<iostream>
using namespace std;

const int N=1e6+10,INF=0x3f3f3f3f;

struct Node
{
    int l,r,key,w,cnt,size;//cnt:当前值有多少个，size当前子树有多少个元素,w随机值控制树高期望是Logn
}tr[N];//平衡树的节点个数是n

int root,idx,n;

int get_node(int key)
{
    tr[++idx].key=key;
    tr[idx].w=rand();
    tr[idx].cnt=tr[idx].size=1;
    return idx;
}

void pushup(int u)
{
    tr[u].size=tr[tr[u].l].size+tr[tr[u].r].size+tr[u].cnt;
}

void zag(int &p) //左旋,引用可直接获得改变的root的值
{
    int q=tr[p].r;
    tr[p].r=tr[q].l,tr[q].l=p,p=q;
    pushup(tr[p].l),pushup(p);
}

void zig(int &p) //右旋
{
    int q=tr[p].l;
    tr[p].l=tr[q].r,tr[q].r=p,p=q;
    pushup(tr[p].r),pushup(p);
}

void build() //初始化平衡树，创建2个哨兵
{
    get_node(-INF),get_node(INF);
    root=1,tr[1].r=2;
    pushup(root);
    if(tr[1].w<tr[2].w) zag(root);//右儿子w大，根节点左旋，让右儿子上去
}

void insert(int &p,int x)
{
    if(!p) p=get_node(x);
    else if(tr[p].key==x) tr[p].cnt++;
    else if(tr[p].key>x) 
    {
        insert(tr[p].l,x);
        if(tr[tr[p].l].w>tr[p].w) zig(p);
    }
    else
    {
        insert(tr[p].r,x);
        if(tr[tr[p].r].w>tr[p].w) zag(p);
    }
    pushup(p);
}

void remove(int &p,int x)
{
    if(!p) return;
    if(tr[p].key==x)
    {
        if(tr[p].cnt>1) tr[p].cnt--;
        else
        {
            if(tr[p].l||tr[p].r)
            {
                if(!tr[p].r||tr[tr[p].l].w>tr[tr[p].r].w)
                {
                    zig(p); remove(tr[p].r,x);
                }
                else
                {
                    zag(p); remove(tr[p].l,x);
                }
            }
            else p=0;
        }
    }
    else if(tr[p].key<x) remove(tr[p].r,x);
    else remove(tr[p].l,x);
    pushup(p);
}

int get_val_by_rank(int p,int rank) //通过排名找数值
{
    if(!p) return INF;
    if(tr[tr[p].l].size>=rank) return get_val_by_rank(tr[p].l,rank);
    if(tr[tr[p].l].size+tr[p].cnt>=rank) return tr[p].key;
    return get_val_by_rank(tr[p].r,rank-tr[tr[p].l].size-tr[p].cnt);
}

int get_rank_by_val(int p,int x) //通过数值找排名
{
    if(!p) return 0;
    if(tr[p].key==x) return tr[tr[p].l].size+1;
    else if(tr[p].key>x) return get_rank_by_val(tr[p].l,x);
    return tr[tr[p].l].size+tr[p].cnt+get_rank_by_val(tr[p].r,x);
}

int get_pre(int p,int x) //找到严格小于x的最大数
{
    if(!p) return -INF;
    if(tr[p].key>=x) return get_pre(tr[p].l,x);
    return max(tr[p].key,get_pre(tr[p].r,x));
}

int get_next(int p,int x) //找到严格大于x的最小数
{
    if(!p) return INF;
    if(tr[p].key<=x) return get_next(tr[p].r,x);
    return min(tr[p].key,get_next(tr[p].l,x));
}

int main()
{
    build();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t,x;scanf("%d%d",&t,&x);
        if(t==1) insert(root,x);
        else if(t==2) remove(root,x);
        else if(t==3) printf("%d\n",get_rank_by_val(root,x)-1); //排名第一的是-INF，root，所以这里要减一
        else if(t==4) printf("%d\n",get_val_by_rank(root,x+1));// 排名第一的是-INF，所以这里要加一
        else if(t==5) printf("%d\n",get_pre(root,x));
        else printf("%d\n",get_next(root,x));
    }
    return 0;
}
