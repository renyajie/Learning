#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int mod=200907;

int qmi(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res=(ll)res*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return res;
}

int main()
{
    int n;scanf("%d",&n);
    while(n--)
    {
        int a,b,c,k;scanf("%d%d%d%d",&a,&b,&c,&k);
        if((ll)a+c==(ll)2*b) printf("%lld\n",(a+(ll)(k-1)*(b-a))%mod); //哪个可能爆int在哪个前面加ll
        else printf("%lld\n",(ll)a*qmi(b/a,k-1)%mod);
    }
    return 0;
}
