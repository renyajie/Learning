#include<iostream>
#include<cstring>
#include<map>
using namespace std;

const int N = 210, M = 110;

int dist[N][N]; // 省略第一维边数
int res[N][N];
int n, m, S, E;
int cnt;

void cal(int c[][N], int a[][N], int b[][N])
{
    static int temp[N][N];
    memset(temp, 0x3f, sizeof temp);
    
    for(int k = 1; k <= cnt; k++)
    {
        for(int i = 1; i <= cnt; i++)
        {
            for(int j = 1; j <= cnt; j++)
            {
                temp[i][j] = min(temp[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    memcpy(c, temp, sizeof temp);
}

void qmi()
{
    memset(res, 0x3f, sizeof res);
    for(int i = 1; i <= cnt; i++) res[i][i] = 0; // 设置快速幂的单位元，整数的单位元是1，而本题的单位元是对角线为0，其余正无穷
    // 这样保证了第一次转移的正确性
    
    while(n)
    {
        if(n & 1) cal(res, res, dist);
        cal(dist, dist, dist);
        n >>= 1;
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &S, &E);
    
    map<int,int> id;
    if(!id.count(S)) id[S] = ++cnt;
    if(!id.count(E)) id[E] = ++cnt;
    S = id[S], E = id[E];
    
    memset(dist, 0x3f, sizeof dist); // 经过0条边的路径不存在，不需要初始化，注意dp含义变化
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c; scanf("%d%d%d", &c, &a, &b);
        if(!id.count(b)) id[b] = ++cnt;
        if(!id.count(a)) id[a] = ++cnt;
        a = id[a], b = id[b];
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }
    
    qmi();
    
    printf("%d\n", res[S][E]);
    
    return 0;
}
