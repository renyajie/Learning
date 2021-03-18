#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=15;
double a[N][N],b[N][N];
int n;

void out()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++) printf("%.3lf ",b[i][j]);
        printf("\n");
    }
}

void gauss()
{
    //out();
    int r,c;
    for(r=1,c=1;c<=n;c++)
    {
        int t=r;
        for(int i=r+1;i<=n;i++) if(fabs(b[i][c])>fabs(b[t][c]))t=i; // 找主元
        if(!fabs(b[t][c]))continue;
        for(int i=c;i<=n+1;i++)swap(b[r][i],b[t][i]);//交换
        for(int i=n+1;i>=c;i--)b[r][i]/=b[r][c]; //归一
        for(int i=r+1;i<=n;i++)// 消元
            for(int j=n+1;j>=c;j--) b[i][j]-=b[i][c]*b[r][j];
        r++;
    }
    
    for(int i=n;i>=1;i--)
        for(int j=i-1;j>=1;j--) {b[j][n+1]-=b[j][i]*b[i][n+1];}
    //out();
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n;j++)scanf("%lf",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){b[i][j]=2*(a[i+1][j]-a[1][j]);b[i][n+1]+=a[i+1][j]*a[i+1][j]-a[1][j]*a[1][j];}
    gauss();
    for(int i=1;i<=n;i++)printf("%.3lf ",b[i][n+1]);
    return 0;
}
