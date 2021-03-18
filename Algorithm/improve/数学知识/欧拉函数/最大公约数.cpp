#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+10,M=1e7+10;//1~N的质数个数n/lnn

typedef long long ll;

int phi[M],prime[N],cnt;
bool st[M];
ll s[M];

void init(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i]){phi[i]=i-1,prime[cnt++]=i;}
        for(int j=0;prime[j]*i<=n;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0){phi[i*prime[j]]=phi[i]*prime[j];break;}
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    for(int i=1;i<=n;i++)s[i]=s[i-1]+phi[i];
}

int main()
{
    int n;scanf("%d",&n);init(n);
    ll ans=0;
    for(int i=0;i<cnt;i++)
    {
        int p=prime[i];
        ans+=2*s[n/p]+1;
    }
    printf("%lld\n",ans);
    return 0;
}
