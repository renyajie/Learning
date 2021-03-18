// �ɳ־û�Ȩֵ�߶���[ά��һ��ֵ��]
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1e5+10,M=1e4+10;
struct Node
{
    int l,r,cnt;//�ɳ־û��߶����洢�������ҽڵ��ָ��
}tr[4*N+N*17];
int idx=0,a[N],d[N],root[N];//root[X]���汾1-X�ĸ��ڵ���

int build(int l,int r)
{
    int p=++idx;//��ǰ�ڵ���
    if(l==r)return p;
    int mid=l+r>>1;
    tr[p].l=build(l,mid),tr[p].r=build(mid+1,r);
    tr[p].cnt=0;
    return p;
}

int insert(int pre,int l,int r,int x) //pre�ϸ��汾��Ӧ�ڵ�ı�� 
{
    int p=++idx;//p���ڱ��
    tr[p]={tr[pre].l,tr[pre].r,tr[pre].cnt+1}; //�ȿɸ�����һ���汾��ͬ�ڵ�����
    if(l==r)return p;
    int mid=l+r>>1;
    if(x<=mid) tr[p].l=insert(tr[pre].l,l,mid,x);
    else tr[p].r=insert(tr[pre].r,mid+1,r,x);
    return p;
}

int query(int q,int p,int l,int r,int k)
{
    if(l==r)return l;
    int cnt=tr[tr[q].l].cnt-tr[tr[p].l].cnt;
    int mid=l+r>>1;
    if(cnt>=k) return query(tr[q].l,tr[p].l,l,mid,k);
    else return query(tr[q].r,tr[p].r,mid+1,r,k-cnt);
}

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {scanf("%d",&d[i]); a[i]=d[i];}
    
    sort(d+1,d+1+n);
    int len=unique(d+1,d+1+n)-(d+1);
    for(int i=1;i<=n;i++) a[i]=lower_bound(d+1,d+1+len,a[i])-d;//a[i]�ǵ�kС��index
    
    root[0]=build(1,len);//root[0]�����ĸ��ڵ��ţ�ά����Χ��1~len
    for(int i=1;i<=n;i++) root[i]=insert(root[i-1],1,len,a[i]);
    for(int i=0;i<m;i++)
    {
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",d[query(root[r],root[l-1],1,len,k)]);//
    }
    return 0;
}
