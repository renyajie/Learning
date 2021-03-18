// ��С��������
// 1. ������С������
// 2. ������������ڵ�֮��������
// 3. ö�ٲ�����С�������ϵıߣ���δ�ֵ�������ϸ��С������ʱ, w > dist[a][b]�����ϸ�ʱ��w >= dist[a][b]
//    res = min(sum - dist[a][b] + w)
// ע�⣺��·��������dist[a][b]���ܻ�ͷ�������ȣ����Ҫ����ϸ�δ����

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N = 510, M = 10010;

struct Edge
{
    int a, b, w;
    bool f;
    bool operator< (const Edge& W) const
    {
        return w < W.w;
    }
}edge[M];

int p[N];
int n, m;
int h[N], e[N * 2], ne[N * 2], wei[N * 2], idx;
int dist[N][N], dist1[N][N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void add(int a, int b, int c)
{
    e[idx] = b, wei[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int father, int maxd, int maxd1, int dist[], int dist1[])
{
    dist[u] = maxd, dist1[u] = maxd1;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;
        
        int t1 = maxd, t2 = maxd1;
        if(wei[i] > t1) t2 = t1, t1 = wei[i];
        else if(wei[i] < t1 && wei[i] > t2) t2 = wei[i]; // ����ϸ�δ�ֵ
        
        dfs(j, u, t1, t2, dist, dist1);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int a, b, w; scanf("%d%d%d", &a, &b, &w);
        edge[i] = {a, b, w};
    }
    
    sort(edge, edge + m);
    for(int i = 1; i <= n; i++) p[i] = i;
    
    
    memset(h, -1, sizeof h);
    ll sum = 0;
    for(int i = 0; i < m; i++)
    {
        int a = find(edge[i].a), b = find(edge[i].b), w = edge[i].w;
        if(a != b)
        {
            p[a] = b;
            edge[i].f = true;
            add(edge[i].a, edge[i].b, w), add(edge[i].b, edge[i].a, w);
            sum += w;
        }
    }
    
    for(int i = 1; i <= n; i++) dfs(i, -1, -1e9, -1e9, dist[i], dist1[i]); // �����ֵ�ͷ��������ʱ�����滻��Ҫ����ϸ�δ�ֵ
    
    ll res = 1e18;
    //cout << sum << endl;
    for(int i = 0; i < m; i++)
    {
        if(edge[i].f) continue;
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        
        if(w > dist[a][b]) res = min(res, sum + w - dist[a][b]);
        else if(w > dist1[a][b]) res = min(res, sum + w - dist1[a][b]);
    }
    
    printf("%lld\n", res);
    
    return 0;
}
