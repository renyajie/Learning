#include<cstdio>
using namespace std;

typedef long long ll;
const int mod=9901;

ll qmi(ll a,ll b)
{
    ll ans=1;
    a%=mod;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

ll get(int k,int p)
{
    if(k==1)return 1;
    if(!(k&1))return (1+qmi(p,k/2))*get(k/2,p)%mod;
    return (get(k-1,p)+qmi(p,k-1))%mod;
}

int main()
{
    ll a,b;scanf("%lld%lld",&a,&b);
    ll ans=1;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            //printf("divisor: %d\n",i);
            int s=0;
            while(a%i==0){a/=i;s++;}
            ans=ans*get(s*b+1,i)%mod;
        }
    }
    if(a>1)ans=ans*get(b+1,a)%mod;
    if(a==0)ans=0;
    printf("%lld\n",ans);
    return 0;
}
