#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 3e5+10, M = N * 2 * 25;

int tr[M][2];
int maxid[M];
int root[N*2], s[N*2];
int n,m,idx=0;

void insert(int u,int pre,int cur) //��ǰ����ڼ������֣���һ��ͬ��εı�ţ����ڵ���һ��εı��
{
    maxid[cur]=u;
    for(int i=24;i>=0;i--)
    {
        int v=s[u]>>i&1;
        if(pre) tr[cur][v^1]=tr[pre][v^1];//���֮ǰ��Ų�Ϊ�գ�˵���ϸ��汾������ͬ�ڵ㣬�Ƚ�֮ǰ��ŵ��������ݿ�¡
        tr[cur][v]=++idx;//�¼���ڵ�ı��
        maxid[tr[cur][v]]=u;
        cur=tr[cur][v],pre=tr[pre][v];
    }
}

int query(int ub,int lb,int c) //��ѯ1~ub���ַ��������ĸ��ڵ���ub��ʼ���ڵ�汾��С��lb�ģ���c�����������
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
    maxid[0]=-1;//�������ַ����ĸ��ڵ���[���汾��]���սڵ��ð汾-1��ʼ��
    s[0]=0;
    root[0]=++idx;//�о��庬��ĵ�Ӱ汾1��ʼ��ʼ�������ڵ��Ų�������������1��25...
    insert(0,0,root[0]);//����s[0]
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
