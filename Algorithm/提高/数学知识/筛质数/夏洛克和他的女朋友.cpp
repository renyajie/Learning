#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+10;

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
            if(i%prime[j]==0)break;
        }
    }
}

int main()
{
    init(N-1);
    int n;scanf("%d",&n);
    puts(n>=3?"2":"1");
    for(int i=1;i<=n;i++)printf(st[i+1]?"2 ":"1 ");
    return 0;
}
