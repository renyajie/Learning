#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e6+10;
typedef long long ll;

int prime[N],cnt;
bool st[N];
int n,p;

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

int qmi(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=(ll)ans*a%p;
        a=(ll)a*a%p;
        b>>=1;
    }
    return ans;
}

int get(int a,int b)
{
    int ans=0;
    while(a){ans+=a/b,a/=b;}
    return ans;
}

int C(int a,int b)
{
    int ans=1;
    for(int i=0;i<cnt;i++)
    {
        int num=prime[i];
        int t=get(a,num)-get(b,num)-get(a-b,num);
        ans=(ll)ans*qmi(num,t)%p;
    }
    return ans;
}

int main()
{
    init(N-1);
    scanf("%d%d",&n,&p);
    int ans=(C(2*n,n)-C(2*n,n-1)+p)%p;
    printf("%d\n",ans);
    return 0;
}
