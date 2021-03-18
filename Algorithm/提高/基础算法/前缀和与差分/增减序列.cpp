#include<iostream>
using namespace std;

const int N=1e5+10;
int a[N],b[N];
typedef long long ll;

int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
    ll p=0,q=0;
    for(int i=2;i<=n;i++)
    {
        if(b[i]>0)p+=b[i];
        else q-=b[i];
    }
    printf("%lld\n%lld\n",max(p,q),abs(p-q)+1);
    return 0;
}
