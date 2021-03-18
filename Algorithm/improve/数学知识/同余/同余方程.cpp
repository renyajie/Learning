#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int exgcd(int a,int b,int &x,int &y)
{
    if(!b) {x=1,y=0;return a;};
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int main()
{
    int a,b,x,y;scanf("%d%d",&a,&b);
    exgcd(a,b,x,y);
    x=(x%b+b)%b;
    printf("%d\n",x);
    return 0;
}
