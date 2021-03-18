#include<cstdio>
using namespace std;

typedef long long ll;

ll qadd(ll a,ll b,ll p)
{
    ll res=0;
    while(b)
    {
        if(b&1)res=(res+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return res;
}

int main()
{
    ll a,b,p;scanf("%lld%lld%lld",&a,&b,&p);
    printf("%lld\n",qadd(a,b,p));
    return 0;
}
