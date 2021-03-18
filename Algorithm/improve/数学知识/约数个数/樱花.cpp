#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=1e6+10,mod=1e9+7;

int prime[N],cnt;
bool st[N];

void init(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])prime[cnt++]=i;
        for(int j=0;prime[j]*i<=n;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0)break;
        }
    }
}

int main()
{
    int n;scanf("%d",&n);init(n);
    ll res=1;
    for(int i=0;i<cnt;i++)
    {
        int p=prime[i],s=0;
        for(int j=n;j;j/=p)s+=j/p;
        res=res*(2*s+1)%mod;
    }
    printf("%lld\n",res);
    return 0;
}
