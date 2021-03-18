#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=20;
typedef long long ll;

ll a[N], b[N];

ll exgcd(ll a,ll b,ll &x,ll &y) 
{
    if(!b) {x=1,y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int main()
{
    int n;scanf("%d",&n); ll m=1;
    for(int i=0;i<n;i++)scanf("%lld%lld",&a[i],&b[i]);
    for(int i=0;i<n;i++)m*=a[i];
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll mi=m/a[i],x,y;
        exgcd(mi,a[i],x,y);
        ans+=b[i]*mi*x;
    }
    printf("%lld\n",(ans%m+m)%m);
    return 0;
}
