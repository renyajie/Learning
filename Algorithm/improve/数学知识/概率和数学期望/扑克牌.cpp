#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=20;
const double INF=1e20;
double f[N][N][N][N][5][5];
int A,B,C,D;

double dp(int a,int b,int c,int d,int x,int y)
{
    double &v=f[a][b][c][d][x][y];
    if(v>=0)return v;
    
    int sum=a+b+c+d+(x!=4)+(y!=4);
    int as=a+(x==0)+(y==0);
    int bs=b+(x==1)+(y==1);
    int cs=c+(x==2)+(y==2);
    int ds=d+(x==3)+(y==3);
    if(as>=A&&bs>=B&&cs>=C&&ds>=D)return v=0;
    if(sum>=54)return v=INF;
    
    v=1;
    if(a<13) v+=1.0*(13-a)/(54-sum)*dp(a+1,b,c,d,x,y);
    if(b<13) v+=1.0*(13-b)/(54-sum)*dp(a,b+1,c,d,x,y);
    if(c<13) v+=1.0*(13-c)/(54-sum)*dp(a,b,c+1,d,x,y);
    if(d<13) v+=1.0*(13-d)/(54-sum)*dp(a,b,c,d+1,x,y);
    if(x==4) 
    {
        double t=INF;
        for(int i=0;i<4;i++) t=min(t,(1.0/(54-sum))*dp(a,b,c,d,i,y));
        v+=t;
    }
    if(y==4) 
    {
        double t=INF;
        for(int i=0;i<4;i++) t=min(t,(1.0/(54-sum))*dp(a,b,c,d,x,i));
        v+=t;
    }
    return v;
}

int main()
{
    scanf("%d%d%d%d",&A,&B,&C,&D);
    memset(f,-1,sizeof f);
    double t=dp(0,0,0,0,4,4);
    if (t > INF / 2) t = -1; //如果其中一个分支不合法是inf，则整个会比INF小，但是不会小太多，用这个判断总的情况
    printf("%.3lf\n",t);
    return 0;
}
