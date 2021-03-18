#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 10010, M = 30010;

int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int ans; // ͳ��һ����������ӵĵ�˫��ͨ�����ֵ
int n, m;
int root;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++timestamp;
    
    int cnt = 0; // ͳ����u�Ǹ�㣬u�����ӵĵ�˫��ͨ�������
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if(dfn[u] <= low[j]) // j���ܵ���u֮ǰ��˵���ҵ�һ����˫��ͨ��
            {
                cnt++;
            }
        }
        else low[u] = min(low[u], dfn[j]);
    }
    
    if(u != root) cnt++; // ���u���Ǹ��ڵ㣬�򵽴�u��·��Ҳ��һ����˫��ͨ�飬������1
    
    ans = max(ans, cnt);
}

int main()
{
    while(scanf("%d%d", &n, &m) && (n || m))
    {
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(h, -1, sizeof h);
        idx = timestamp = ans = root = 0;
        
        for(int i = 0; i < m; i ++)
        {
            int a, b; scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
        }
        
        int cnt = 0;
        for(root = 0; root < n; root++)
        {
            if(!dfn[root])
            {
                cnt++;
                tarjan(root);
            }
        }
        
        printf("%d\n", ans + cnt - 1);
    }
    
    return 0;
}
