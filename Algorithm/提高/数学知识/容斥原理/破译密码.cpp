#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=50010;
int prime[N],cnt;
bool st[N];
int mobius[N],sum[N];

void init(int n)
{
    mobius[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i]){prime[cnt++]=i,mobius[i]=-1;}
        for(int j=0;prime[j]*i<=n;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0){mobius[i*prime[j]]=0;break;}
            mobius[i*prime[j]]=mobius[i]*(-1);
        }
    }
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+mobius[i];
}

int main()
{
    init(N-1);
    int T;scanf("%d",&T);
    while(T--)
    {
        int a,b,d;scanf("%d%d%d",&a,&b,&d);
        a/=d,b/=d;
        int n=min(a,b);
        int ans=0;
        for(int l=1,r=1;l<=n;l=r+1)//g(x)=a/(a/x)
        {
            r=min(n,min(a/(a/l),b/(b/l)));// 跳过一整段值一样的，变成根号n的复杂度
            ans+=(a/r)*(b/r)*(sum[r]-sum[l-1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
