//��Լ���ֽ⣬��dfs�õ�����Լ����ö������Լ��
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=5e4+10;//2e9�ڵ���������
typedef long long ll;

int prime[N],cnt;
bool st[N];

struct Fac
{
    int p,s;
}fa[N];
int fcnt;
int divisor[1601],dcnt; //2e9��Χ��Լ������

void init(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])prime[cnt++]=i;
        for(int j=0;prime[j]*i<=n;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0)break;
        }
    }
}

void dfs(int u,int x)
{
    if(u==fcnt){divisor[dcnt++]=x;return;}
    int p=x;
    for(int i=0;i<=fa[u].s;i++){dfs(u+1,p);p*=fa[u].p;}
}

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    init(N-1);
    int n;scanf("%d",&n);
    while(n--)
    {
        fcnt=dcnt=0;
        int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
        int t=d;
        for(int i=0;prime[i]<=t/prime[i];i++)
        {
            int p=prime[i],s=0;
            if(t%p)continue;
            while(t%p==0) t/=p,s++;
            fa[fcnt++]={p,s};
        }
        if(t>1)fa[fcnt++]={t,1};//ע����t>1����t>0
        dfs(0,1);
        int ans=0;
        for(int i=0;i<dcnt;i++)
        {
            int x=divisor[i];
            if(gcd(x,a)==b&&(ll)x*c/gcd(x,c)==d)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
