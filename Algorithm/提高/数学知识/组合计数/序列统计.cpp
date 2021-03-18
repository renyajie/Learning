#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+10,mod=1e6+3;
typedef long long ll;

int qmi(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=(ll)ans*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return ans;
}

int C(int a,int b)
{
    if(a<b)return 0;
    int up=1,down=1;
    for(int i=a,j=1;i>b;i--,j++){up=(ll)up*i%mod,down=(ll)down*j%mod;}
    int ans=(ll)up*qmi(down,mod-2)%mod;
    return ans;
}

int lucas(int a,int b)
{
    if(a<mod&&b<mod)return C(a,b);
    return (ll)lucas(a%mod,b%mod)*lucas(a/mod,b/mod)%mod;
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,l,r;scanf("%d%d%d",&n,&l,&r);
        int ans=lucas(r-l+n+1,r-l+1)-1;
        printf("%d\n",(ans+mod)%mod);
    }
    return 0;
}
