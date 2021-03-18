#include<iostream>
using namespace std;

const int N=100010;
double a[N],s[N];
int n,m;

bool check(double x)
{
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]-x;
    double mins=0;
    for(int i=m;i<=n;i++)
    {
        mins=min(mins,s[i-m]);
        if(s[i]-mins>=0)return true;
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    double l=0,r=0;
    for(int i=1;i<=n;i++){scanf("%lf",&a[i]);r=max(r,a[i]);}
    while(r-l>1e-5)
    {
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%d\n",int(r*1000));
    return 0;
}
