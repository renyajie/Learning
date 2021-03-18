#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1010, M = 2e5 + 10;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

int S, T, K, n, m;
int h[N], rh[N], e[M], ne[M], w[M], idx;
int rd[N];
bool st[N];
int cnt[N];

void init()
{
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof h);
    idx = 0;
}

void add(int h[], int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    memset(rd, 0x3f, sizeof rd);
    rd[T] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, T});
    
    while(pq.size())
    {
        auto p = pq.top(); pq.pop();
        
        int cur = p.second;
        if(st[cur]) continue;
        st[cur] = true;
        
        for(int i = rh[cur]; ~i; i = ne[i])
        {
            int j = e[i];
            if(!st[j] && rd[j] > rd[cur] + w[i])
            {
                rd[j] = rd[cur] + w[i];
                pq.push({rd[j], j});
            }
        }
    }
    
}

int A()
{
    priority_queue<PIII, vector<PIII>, greater<PIII>> pq;
    pq.push({rd[S], {0, S}});
    
    
    while(pq.size())
    {
        auto p = pq.top(); pq.pop();
        
        int cur = p.second.second;
        int dis = p.second.first;
        
        cnt[cur]++;
        if(cnt[T] == K) return dis;
        
        for(int i = h[cur]; ~i; i = ne[i])
        {
            int j = e[i];
            
            int d = dis + w[i];
            if(cnt[j] < K)
            {
                pq.push({rd[j] + d, {d, j}});
            }
        }
    }
    
    return -1;
}

int main()
{
    init();
    
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(h, a, b, c), add(rh, b, a, c);
    }
    scanf("%d%d%d", &S, &T, &K);
    
    dijkstra();
    
    if(S == T) K++;
    int ans = A();
    
    printf("%d\n", ans);
    
    return 0;
}
