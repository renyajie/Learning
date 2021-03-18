#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=60,M=1010;

int tr[N*20][4],cnt[N*20],idx;
int q[N*20],ne[N*20];
int dp[M][N*20];
char str[M];

int get(char c)
{
    if(c=='A') return 0;
    if(c=='G') return 1;
    if(c=='C') return 2;
    return 3;
}

void insert()
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int c=get(str[i]);
        if(!tr[p][c]) tr[p][c]=++idx;
        p=tr[p][c];
    }
    cnt[p]=1;
}

void build()
{
    int hh=0,tt=-1;
    for(int i=0;i<4;i++) if(tr[0][i]) q[++tt]=tr[0][i];
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=0;i<4;i++)
        {
            int c=tr[t][i];
            if(!c) tr[t][i]=tr[ne[t]][i];
            else {ne[c]=tr[ne[t]][i]; q[++tt]=c;cnt[c]|=cnt[ne[c]];}
        }
    }
}

int main()
{
    int n,T=1;
    while(scanf("%d",&n),n)
    {
        memset(tr,0,sizeof tr),memset(cnt,0,sizeof cnt),memset(ne,0,sizeof ne),idx=0;
        for(int i=0;i<n;i++){scanf("%s",str);insert();}
        build(); 
        scanf("%s",str+1);
        memset(dp,0x3f,sizeof dp); dp[0][0]=0;
        int m=strlen(str+1);
        for(int i=0;i<m;i++)
            for(int j=0;j<=idx;j++)
                for(int k=0;k<4;k++)
                {
                    int p=tr[j][k],t=get(str[i+1])!=k;
                    if(!cnt[p]) dp[i+1][p]=min(dp[i+1][p],dp[i][j]+t);
                }
        int ans=0x3f3f3f3f;
        for(int i=0;i<=idx;i++) ans=min(ans,dp[m][i]);
        if(ans==0x3f3f3f3f) ans=-1;
        printf("Case %d: %d\n",T++,ans);
    }
    return 0;
}
