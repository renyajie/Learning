#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1010;

int dp[1010][110][150],k,x;

int qmi(int a,int b,int m)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%m;
        a=a*a%m;
        b>>=1;
    }
    return ans;
}

void add(int C[],int A[],int B[])
{
    for(int i=0,t=0;i<N;i++)
    {
        t+=A[i]+B[i];
        C[i]=t%10;
        t/=10;
    }
}

int main()
{
    scanf("%d%d",&k,&x);
    int n=qmi(x%1000,x,1000);
    memset(dp,0,sizeof dp);
    for(int i=0;i<n;i++)
        for(int j=0;j<k&&j<=i;j++)//注意j<=i
            if(!j) dp[i][j][0]=1;
            else add(dp[i][j],dp[i-1][j-1],dp[i-1][j]);
    int *g=dp[n-1][k-1];
    int i=149;//这里取最高位
    while(g[i]==0)i--;
    while(i>=0)printf("%d",g[i--]);
    return 0;
}
