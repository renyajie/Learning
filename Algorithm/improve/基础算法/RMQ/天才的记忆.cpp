#include<iostream>
#include<cmath>
using namespace std;

const int N=18,M=2e5+10;
int f[N][M],a[M];
int n,m;

void init()
{
    for(int i=0;i<N;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            if(i==0)f[i][j]=a[j];
            else f[i][j]=max(f[i-1][j],f[i-1][j+(1<<i-1)]);
        }
}

int query(int l,int r)
{
    int len=log(r-l+1)/log(2);
    int ans=max(f[len][l],f[len][r-(1<<len)+1]);
    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    init();
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }
    return 0;
}
