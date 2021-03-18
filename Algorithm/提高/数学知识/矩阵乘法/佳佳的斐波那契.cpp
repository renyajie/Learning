#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

void mul(int C[],int A[],int B[][4],int m)
{
    int ans[4]={0};
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            ans[i]=(ans[i]+(ll)A[j]*B[j][i])%m;
    memcpy(C,ans,sizeof ans);
}

void mul(int C[][4],int A[][4],int B[][4],int m)
{
    int ans[4][4]={0};
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                ans[i][j]=(ans[i][j]+(ll)A[i][k]*B[k][j])%m;
    memcpy(C,ans,sizeof ans);
}

void qmi(int A[],int B[][4],int b,int m)
{
    while(b)
    {
        if(b&1)mul(A,A,B,m);
        mul(B,B,B,m);
        b>>=1;
    }
}

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    int A[4]={1,1,1,0};
    int B[4][4]={{0,1,0,0},{1,1,1,0},{0,0,1,1},{0,0,0,1}};
    qmi(A,B,n-1,m);
    printf("%d\n",(((ll)n*A[2]-A[3])%m+m)%m);
    return 0;
}
