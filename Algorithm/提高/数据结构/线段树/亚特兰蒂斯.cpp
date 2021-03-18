#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 10010;

struct Line
{
    double x,y1,y2;
    int add;
    bool operator<(const Line& W) const {return x<W.x;}
}line[N*2];

struct Node
{
    int l,r,cnt; // 区间被完整覆盖多少次
    double len; // 有效覆盖长度
}tr[N*8];

vector<double> ys;
int n;

int find(double x)
{
    int l=0,r=ys.size()-1;
    while(l<r)
    {
        int mid=l+r>>1;
        if(ys[mid]>=x) r=mid;
        else l=mid+1;
    }
    return l;
}

void pushup(int u)
{
    if(tr[u].cnt) tr[u].len=ys[tr[u].r+1]-ys[tr[u].l];
    else if(tr[u].l!=tr[u].r) tr[u].len=tr[u<<1].len+tr[u<<1|1].len;
    else tr[u].len=0;
}

void build(int u, int l, int r)
{
    tr[u]={l,r,0,0};
    if(l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u, int l, int r, int add)
{
    if(tr[u].l>=l && tr[u].r<=r) {tr[u].cnt+=add,pushup(u); return;}
    int mid=tr[u].l+tr[u].r>>1;
    if(l<=mid) modify(u<<1,l,r,add);
    if(r>mid) modify(u<<1|1,l,r,add);
    pushup(u);
}

int main()
{
    int T = 1;
    while(scanf("%d", &n) == 1 && n)
    {
        ys.clear();
        for(int i=0,j=0;i<n;i++)
        {
            double x1,y1,x2,y2; scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            line[j++]={x1,y1,y2,1},line[j++]={x2,y1,y2,-1};
            ys.push_back(y1),ys.push_back(y2);
        }
        sort(ys.begin(),ys.end());
        ys.erase(unique(ys.begin(),ys.end()),ys.end());
        build(1,0,ys.size()-2);
        
        double ans=0;
        sort(line,line+2*n);
        for(int i=0;i<2*n;i++)
        {
            if(i) ans+=tr[1].len*(line[i].x-line[i-1].x);
            modify(1,find(line[i].y1),find(line[i].y2)-1,line[i].add);
        }
        
        printf("Test case #%d\n", T++);
        printf("Total explored area: %.2lf\n\n", ans);
    }
    return 0;
}
