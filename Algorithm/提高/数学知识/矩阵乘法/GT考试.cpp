#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=30;
typedef long long ll;

int ne[N],a[N][N],dp[N];
char str[N];
int n,m,mod;

void mul(int C[],int A[],int B[][30])
{
    int ans[N]={0};
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            ans[j]=(ans[j]+(ll)A[i]*B[i][j])%mod;
    memcpy(C,ans,sizeof ans);
}

void mul(int C[][30],int A[][30],int B[][30])
{
    int ans[N][N]={0};
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<m;k++)
                ans[j][k]=(ans[j][k]+A[j][i]*B[i][k])%mod;
    memcpy(C,ans,sizeof ans);
}

void qmi(int b)
{
    dp[0]=1;
    while(b)
    {
        if(b&1)mul(dp,dp,a);
        mul(a,a,a);
        b>>=1;
    }
}

int main()
{
    scanf("%d%d%d%s",&n,&m,&mod,str+1);
    for(int i=2,j=0;i<=m;i++)
    {
        while(j&&str[i]!=str[j+1])j=ne[j];
        if(str[i]==str[j+1])j++;
        ne[i]=j;
    }
    for(int i=0;i<m;i++)
        for(int j='0';j<='9';j++)
        {
            int k=i;
            while(k&&str[k+1]!=j)k=ne[k];
            if(str[k+1]==j)k++;
            a[i][k]++;
        }
    qmi(n);
    int ans=0;
    for(int i=0;i<m;i++)ans=(ans+dp[i])%mod;
    printf("%d\n",ans);
    return 0;
}
