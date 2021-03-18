#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010, M = 400010;

int h[N], e[M], ne[M], idx;
int used[M];
int ans[M / 2];
int ind[N], outd[N];
int cnt;
int type;
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    for(int &i = h[u]; ~i;)
    {
        if(used[i])
        {
            i = ne[i];
            continue;
        }
        
        used[i] = true; // 标记这条边被删除
        if(type == 1) used[i ^ 1] = true; // 无向图标记反向边被删除 
        
        int t;
        if(type == 1)
        {
            t = i / 2 + 1;
            if(i & 1) t = -t;
        }
        else
        {
            t = i + 1;
        }
        
        int j = e[i];
        i = ne[i]; // 在递归之前删除这条边
        
        dfs(j);
        
        ans[++cnt] = t;
        
    }
}

int main()
{
    scanf("%d", &type);
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++)
    {
        int a, b; scanf("%d%d", &a, &b);
        add(a, b);
        if(type == 1) add(b, a);
        ind[b]++, outd[a]++;
    }
    
    bool success = true;
    if(type == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            if((ind[i] + outd[i]) & 1)
            {
                success = false;
                break;
            }
        }
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(ind[i] != outd[i])
            {
                success = false;
                break;
            }
        }
    }
    
    for (int i = 1; i <= n; i ++ )
        if (h[i] != -1)
        {
            dfs(i);
            break;
        }

    if (cnt < m)
    {
        success = false;
    }
    
    if(!success) puts("NO");
    else
    {
        puts("YES");
        for(int i = cnt; i; i--) printf("%d ", ans[i]);
        printf("\n");
    }
    
    return 0;
}
