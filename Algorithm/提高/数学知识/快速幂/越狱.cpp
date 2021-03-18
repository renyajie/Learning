#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int mod=100003;
typedef long long ll;

int qmi(int a,ll b)
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
    ll n,m;scanf("%lld%lld",&m,&n);
    printf("%d\n",(qmi(m,n)-(ll)m*qmi(m-1,n-1)%mod+mod)%mod);
}
