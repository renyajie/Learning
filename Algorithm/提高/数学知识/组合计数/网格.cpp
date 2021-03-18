#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=10010;

int a[N],b[N];
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

int get(int a,int b)
{
    int ans=0;
    while(a) ans+=a/b,a/=b;
    return ans;
}

void mul(int A[],int b)
{
    for(int i=0,t=0;i<N;i++)
    {
        t=A[i]*b+t;
        A[i]=t%10;
        t/=10;
    }
}

int C(int A[],int a,int b)
{
    A[0]=1;
    for(int i=0;i<cnt;i++)
    {
        int p=prime[i];
        int t=get(a,p)-get(b,p)-get(a-b,p);
        for(int j=0;j<t;j++) mul(A,p);
    }
    int ans=N-1;
    while(!A[ans]&&ans)ans--;
    return ans;
}

void sub(int al,int A[],int bl,int B[])
{
    for(int i=0,t=0;i<=al;i++)
    {
        A[i]-=t+B[i];
        if(A[i]<0){A[i]+=10,t=1;}
        else t=0;
    }
}

int main()
{
    init(N-1);
    int n,m;scanf("%d%d",&n,&m);
    int al=C(a,n+m,n), bl=C(b,n+m,m-1);
    sub(al,a,bl,b);
    while(!a[al]&&al)al--;
    while(al>=0)printf("%d",a[al--]);
    printf("\n");
    return 0;
}
