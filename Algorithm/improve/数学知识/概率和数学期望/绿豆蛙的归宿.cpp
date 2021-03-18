#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+10,M=2*N;
int h[N],e[M],ne[M],w[M],idx;
int dout[N];
double f[N];
int n,m;

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

double dp(int u)
{
    if(u==n)return 0;
    double &v=f[u];
    if(v>=0)return v;
    v=0;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        v+=1.0*(w[i]+dp(j))/dout[u];
    }
    return v;
}

int main()
{
    memset(h,-1,sizeof h),idx=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),dout[a]++;
    }
    memset(f,-1,sizeof f);
    printf("%.2lf\n",dp(1));
    return 0;
}
