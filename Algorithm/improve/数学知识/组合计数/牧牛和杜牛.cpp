#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+10,mod=5000011;

int a[N],s[N],dp[N],n,k;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dp[0]=s[0]=1;
    for(int i=1;i<=n;i++){dp[i]=s[max(i-k-1,0)],s[i]=(s[i-1]+dp[i])%mod;}
    printf("%d\n",s[n]);
    return 0;
}
