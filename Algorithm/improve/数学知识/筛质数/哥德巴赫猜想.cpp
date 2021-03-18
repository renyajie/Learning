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
        if(!st[i]) prime[cnt++]=i;
        for(int j=0;prime[j]*i<=n;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    init(N-1);
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;;i++)
        {
            int b=n-prime[i];
            if(!st[b]) {printf("%d = %d + %d\n",n,prime[i],b); break;}
        }
    }
    return 0;
}
