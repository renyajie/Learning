#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=40;
int a[N][N],n;

int gauss()
{
    int r,c;
    for(r=1,c=1;c<=n;c++)
    {
        int t=r;//主元
        for(int i=r+1;i<=n;i++)if(a[i][c])t=i;
        if(!a[t][c])continue;
        for(int i=c;i<=n+1;i++)swap(a[r][i],a[t][i]);//交换，因为都是1不需要归一
        for(int i=r+1;i<=n;i++)//消元   
            for(int j=n+1;j>=c;j--) a[i][j]^=a[i][c]&a[r][j];
        r++;
    }
    if(r<n+1)
    {
        for(int i=r;i<=n;i++)if(a[i][n+1])return-1;
        int ans=1;
        for(int i=r;i<=n;i++)ans*=2;
        return ans;
    }
    return 1;
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i][n+1]);
        for(int i=1;i<=n;i++)
        {
            int t;scanf("%d",&t);
            a[i][n+1]^=t,a[i][i]=1;
        }
        int x,y;
        while(scanf("%d%d",&x,&y)==2&&(x||y))a[y][x]=1;
        int ans=gauss();
        if(ans==-1)printf("Oh,it's impossible~!!\n");
        else printf("%d\n",ans);
    }
    return 0;
}
