#include<cstdio>
#include<iostream>
using namespace std;

const int N=5010;
int s[N][N];

int main()
{
    int n,r;scanf("%d%d",&n,&r);
    r=min(5001,r);
    for(int i=0;i<n;i++)
    {
        int x,y,w;scanf("%d%d%d",&x,&y,&w);
        s[x+1][y+1]+=w;
    }
    for(int i=1;i<=5001;i++)
        for(int j=1;j<=5001;j++)
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    int ans=0;
    for(int i=r;i<=5001;i++)
        for(int j=r;j<=5001;j++)
            ans=max(ans,s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r]);
    printf("%d\n",ans);
    return 0;
}
