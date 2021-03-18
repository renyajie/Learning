#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
struct Point{ll x,y;};

Point get(ll n,ll id)
{
    if(!n)return {0,0};
    ll block=1ll<<(2*n-2),z=id/block,len=1ll<<n-1;
    auto p=get(n-1,id%block);
    ll x=p.x,y=p.y;
    if(z==0)return {y,x};
    else if(z==1)return {x,y+len};
    else if(z==2)return {x+len,y+len};
    return {2*len-1-y,len-1-x};
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        ll n,a,b;scanf("%lld%lld%lld",&n,&a,&b);
        auto p1=get(n,a-1),p2=get(n,b-1);
        double dx=p1.x-p2.x,dy=p1.y-p2.y;
        double ans=sqrt(dx*dx+dy*dy)*10;
        printf("%.0lf\n",ans);
    }
    return 0;
}
