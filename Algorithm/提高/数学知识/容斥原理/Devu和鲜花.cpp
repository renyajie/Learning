#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=30,mod=1e9+7;
typedef long long ll;
ll A[N],n;
ll m;

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

int C(ll a,ll b)
{
    if(b>a)return 0;
    ll up=1,down=1;
    for(ll i=a,j=1;i>=a-b+1;i--,j++) up=i%mod*up%mod,down=j%mod*down%mod;
    down=qmi(down,mod-2);
    return up*down%mod;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++)scanf("%lld",&A[i]);
    int res=0;
    for(int i=0;i<1<<n;i++)
    {
        ll a=m+n-1,b=n-1;
        int sign=1;
        for(int j=0;j<n;j++)
        {
            if(i>>j&1)
            {
                sign*=-1;
                a-=A[j]+1;
            }
        }
        res=((ll)res+C(a,b)*sign+mod)%mod;
    }
    printf("%d\n",res);
    return 0;
}
