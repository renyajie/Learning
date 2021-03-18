#include<iostream>
using namespace std;

const int N=500010;
typedef long long ll;
int a[N],w[N],n;

ll merge(int l,int r)
{
    if(l>=r)return 0;
    int mid=l+r>>1;
    ll ans=merge(l,mid)+merge(mid+1,r);
    int i=l,j=mid+1,cnt=0;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])w[cnt++]=a[i++];
        else
        {
            ans+=mid-i+1;
            w[cnt++]=a[j++];
        }
    }
    while(i<=mid)w[cnt++]=a[i++];
    while(j<=r)w[cnt++]=a[j++];
    for(int i=l,j=0;i<=r;i++,j++)a[i]=w[j];
    return ans;
}

int main()
{
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        ll ans=merge(0,n-1);
        printf("%lld\n",ans);
    }
    return 0;
}
