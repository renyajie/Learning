#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 3e5+10, M = N * 2 * 25;

int tr[M][2];
int maxid[M];
int root[N*2], s[N*2];
int n,m,idx=0;

void insert(int u,int pre,int cur) //当前插入第几个数字，上一个同层次的编号，现在的这一层次的编号
{
    maxid[cur]=u;
    for(int i=24;i>=0;i--)
    {
        int v=s[u]>>i&1;
        if(pre) tr[cur][v^1]=tr[pre][v^1];//如果之前编号不为空，说明上个版本存在相同节点，先将之前编号的其他数据克隆
        tr[cur][v]=++idx;//新加入节点的编号
        maxid[tr[cur][v]]=u;
        cur=tr[cur][v],pre=tr[pre][v];
    }
}

int query(int ub,int lb,int c) //查询1~ub个字符串插入后的根节点编号ub开始，节点版本不小于lb的，和c异或最大的数字
{
    int ans = 0;
    for(int i=24;i>=0;i--)
    {
        int v=c>>i&1;
        if(maxid[tr[ub][v^1]]>=lb) ub=tr[ub][v^1];
        else ub=tr[ub][v];
    }
    return s[maxid[ub]];
}

int main()
{
    scanf("%d%d",&n,&m);
    maxid[0]=-1;//存所有字符串的根节点编号[即版本号]，空节点用版本-1初始化
    s[0]=0;
    root[0]=++idx;//有具体含义的点从版本1开始初始化，根节点编号不连续，可能是1，25...
    insert(0,0,root[0]);//插入s[0]
    for(int i=1;i<=n;i++)
    {
        int x; scanf("%d",&x);
        s[i]=s[i-1]^x;
        root[i]=++idx;
        insert(i,root[i-1],root[i]);
    }
    char op[2];
    int l,r,x;
    for(int i=0;i<m;i++)
    {
        scanf("%s",op);
        if(op[0]=='A')
        {
            scanf("%d",&x);
            s[n+1]=s[n]^x;
            root[n+1]=++idx;
            insert(n+1,root[n],root[n+1]);
            n++;
        }
        else
        {
            scanf("%d%d%d",&l,&r,&x);
            printf("%d\n",query(root[r-1],l-1,s[n]^x)^(s[n]^x));
        }
    }
    return 0;
}
