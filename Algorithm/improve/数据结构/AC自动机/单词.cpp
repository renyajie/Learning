#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+10;

int tr[N][26],idx;
int q[N],ne[N];
int dp[N],id[210];
char str[N];

void insert(int x)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int c=str[i]-'a';
        if(!tr[p][c]) tr[p][c]=++idx;
        p=tr[p][c];
        dp[p]++;
    }
    id[x]=p;//记录每个单词的编号
}

void build()
{
    int hh=0,tt=-1;
    for(int i=0;i<26;i++) if(tr[0][i]) q[++tt]=tr[0][i];
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=0;i<26;i++)
        {
            int c=tr[t][i];
            if(!c) tr[t][i]=tr[ne[t]][i];
            else {ne[c]=tr[ne[t]][i];q[++tt]=c;}
        }
    }
}

int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%s",str);insert(i);}
    build();
    for(int i=idx-1;i>=0;i--) dp[ne[q[i]]]+=dp[q[i]];//按照拓扑序累加，队列一共有idx个元素，从idx-1开始
    for(int i=0;i<n;i++) printf("%d\n",dp[id[i]]);
    return 0;
}
