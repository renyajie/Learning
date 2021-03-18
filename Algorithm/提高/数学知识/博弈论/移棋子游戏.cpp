#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

const int N=2010,M=6010;
int h[N],e[M],ne[M],idx;
int f[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int sg(int u)
{
    if(f[u]>=0)return f[u];
    f[u]=0;
    set<int> s;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        s.insert(sg(j));
    }
    for(int i=0;;i++) if(s.count(i)==0) {f[u]=i;break;}
    return f[u];
}

int main()
{
    memset(h,-1,sizeof h),idx=0;
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        add(x,y);
    }
    int ans=0;
    memset(f,-1,sizeof f);
    for(int i=0;i<k;i++)
    {
        int t;scanf("%d",&t);
        ans^=sg(t);
    }
    if(ans)puts("win");
    else puts("lose");
    return 0;
}
