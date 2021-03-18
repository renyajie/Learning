#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+10,M=1e6+10;

int a[N],s[M],cnt[M];


int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);cnt[a[i]]++;}
    for(int i=1;i<M;i++)
    {
        for(int j=i;j<M;j+=i) s[j]+=cnt[i];
    }
    for(int i=1;i<=n;i++)printf("%d\n",s[a[i]]-1);
    return 0;
}
