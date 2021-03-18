#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+10;

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
    for(int i=0;i<cnt;i++)
    {
        int cnt=0,p=prime[i];
        for(int j=n;j;j/=p)cnt+=j/p;
        printf("%d %d\n",p,cnt);
    }
    return 0;
}
