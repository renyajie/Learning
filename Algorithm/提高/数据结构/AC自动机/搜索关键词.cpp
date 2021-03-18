#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e4+10,M=1e6+10;

int tr[N*50][26],cnt[N*50],idx;
int q[N*50],ne[N*50];
char str[M];

void insert()
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int j=str[i]-'a';
        if(!tr[p][j]) tr[p][j]=++idx;
        p=tr[p][j];
    }
    cnt[p]++;
}

void build()
{
    int hh=0,tt=-1;
    for(int i=0;i<26;i++)
        if(tr[0][i]) q[++tt]=tr[0][i];
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=0;i<26;i++)
        {
            int c=tr[t][i];
            if(!c) tr[t][i]=tr[ne[t]][i];//tr[t]所有情况都能走到，要么往下要么跳转
            else
            {
                ne[c]=tr[ne[t]][i];
                q[++tt]=c;
            }
        }
    }
}

int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n;scanf("%d",&n);
        memset(tr,0,sizeof tr),memset(cnt,0,sizeof cnt),memset(ne,0,sizeof ne);
        idx=0;
        for(int i=0;i<n;i++) { scanf("%s",str); insert();}
        build();
        scanf("%s",str);
        int ans=0;
        for(int i=0,j=0;str[i];i++)
        {
            int c=str[i]-'a';
            j=tr[j][c];//j走到下个位置
            int p=j;//一次性统计所有单词数量
            while(p)
            {
                ans+=cnt[p];
                cnt[p]=0;//防止重复计数
                p=ne[p];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
