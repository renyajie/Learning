#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010;
typedef long long ll;

int row[N],col[N],c[N];

ll get(int A[],int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)sum+=A[i];
    if(sum%n)return -1;
    int x=sum/n;
    for(int i=2;i<=n;i++)c[i]=c[i-1]+A[i]-x;
    sort(c+1,c+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=abs(c[i]-c[1+n>>1]);
    return ans;
}

int main()
{
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        row[x]++,col[y]++;
    }
    ll ra=get(row,n);
    ll rb=get(col,m);
    if(ra!=-1&&rb!=-1)printf("both %lld\n",ra+rb);
    else if(ra!=-1)printf("row %lld\n",ra);
    else if(rb!=-1)printf("column %lld\n",rb);
    else printf("impossible\n");
    return 0;
}
