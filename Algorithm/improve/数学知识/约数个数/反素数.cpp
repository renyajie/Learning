#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

int prime[]={2,3,5,7,11,13,17,19,23};
int maxd,num,n;

void dfs(int u,int ub,int d,int x)
{
    if(d>maxd||d==maxd&&x<num){maxd=d,num=x;}
    if(u==9)return;
    
    int p=x;
    for(int i=0;i<=ub;i++)
    {
        dfs(u+1,i,d*(i+1),p);
        if((ll)p*prime[u]>n)break;
        p*=prime[u];
    }
}

int main()
{
    scanf("%d",&n);
    dfs(0,30,1,1);
    printf("%d\n",num);
    return 0;
}
