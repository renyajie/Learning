#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1010;

int phi[N],prime[N],cnt;
bool st[N];

void init(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i]){prime[cnt++]=i,phi[i]=i-1;}
        for(int j=0;prime[j]*i<=n;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0){phi[i*prime[j]]=phi[i]*prime[j];break;}
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
}

int main()
{
    init(N-1);
    int T;scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int n;scanf("%d",&n);
        int ans=1;
        for(int j=1;j<=n;j++)ans+=2*phi[j];
        printf("%d %d %d\n",i,n,ans);
    }
    return 0;
}
