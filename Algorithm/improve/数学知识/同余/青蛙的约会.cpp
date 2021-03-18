#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b){x=1,y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int main()
{
    ll x,y,m,n,L;scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L);
    ll a=m-n,b=L,c=y-x;
    ll d=exgcd(a,b,x,y);
    if(c%d)puts("Impossible");
    else
    {
        x*=c/d;
        ll t=abs(L/d);x=(x%t+t)%t;printf("%lld\n",x);
    }
    return 0;
}
