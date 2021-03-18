#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
int n,m;

void mul(int C[],int A[],int B[][3],int m)
{
    int ans[3]={0};
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            ans[i]=(ans[i]+(ll)A[j]*B[j][i])%m;
    memcpy(C,ans,sizeof ans);
}

void mul(int C[][3],int A[][3],int B[][3],int m)
{
    int ans[3][3]={0};
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                ans[i][j]=(ans[i][j]+(ll)A[i][k]*B[k][j])%m;
    memcpy(C,ans,sizeof ans);
}

void qmi(int C[],int A[][3],int b,int m)
{
    while(b)
    {
        if(b&1)mul(C,C,A,m);//ע������ĵ�λԪ����A[3]={1,1,1}������������ans[3][3]�������岻��
        mul(A,A,A,m);
        b>>=1;
    }
}

int main()
{
    int A[3]={1,1,1};
    int B[3][3]={{0,1,0},{1,1,1},{0,0,1}};
    scanf("%d%d",&n,&m);
    qmi(A,B,n-1,m);
    printf("%d\n",A[2]);
    return 0;
}
