#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=2010,mod=100003; //因为会有a+c-1，所以数组开2倍范围

int fact[N], infact[N];

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

void init()
{
    memset(fact,0,sizeof fact),memset(infact,0,sizeof infact);
    fact[0]=infact[0]=1;//按定义结合逆元算的时候，从0开始
    for(int i=1;i<N;i++)
    {
        fact[i]=(ll)fact[i-1]*i%mod;
        infact[i]=(ll)infact[i-1]*qmi(i,mod-2)%mod;
    }
}

int C(int a,int b)
{
    if(b>a)return 0;
    return (ll)fact[a]*infact[b]%mod*infact[a-b]%mod;
}

int A(int a,int b)
{
    if(b>a)return 0;
    return (ll)fact[a]*infact[a-b]%mod;
}

int main()
{
    init();
    int a,b,c,d,k;scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
    int ans=0;
    for(int i=0;i<=k;i++) {int j=k-i;ans=(ans+(ll)C(b,i)*A(a,i)%mod*C(d,j)%mod*A(a+c-i,j)%mod)%mod;}
    printf("%d\n",ans);
    return 0;
}
