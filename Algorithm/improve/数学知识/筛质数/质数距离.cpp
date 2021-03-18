#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+10;

typedef long long ll;

int prime[N],cnt;
bool st[N];

void init(int n)
{
    memset(st,0,sizeof st),cnt=0;
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
    int l,r;
    while(scanf("%d%d",&l,&r)==2)
    {
        init(60000);
        memset(st,0,sizeof st);
        for(int i=0;i<cnt;i++)
        {
            ll p=prime[i];
            for(ll j=max(2*p,(l+p-1)/p*p);j<=r;j+=p) st[j-l]=true;
        }
        int all=0;
        
        for(int i=0;i<=r-l;i++) if(!st[i]&&i+l>1) prime[all++]=i+l;
        if(all<2) {printf("There are no adjacent primes.\n");continue;}
        int minp=0,maxp=0;
        for(int i=0;i+1<all;i++)
        {
            if(prime[i+1]-prime[i]<prime[minp+1]-prime[minp]) minp=i;
            if(prime[i+1]-prime[i]>prime[maxp+1]-prime[maxp]) maxp=i;
        }
        printf("%d,%d are closest, %d,%d are most distant.\n",
        prime[minp],prime[minp+1],prime[maxp],prime[maxp+1]);
    }
    return 0;
}
/*
1 100
1000000000 1001000000
1000000000 1000000008
2147483587 2147483647
2147481000 2147483646
1 2
2 3
*/
