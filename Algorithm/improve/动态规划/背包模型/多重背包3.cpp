#include<cstring>
#include<iostream>
using namespace std;

const int N = 20010;

int g[N], f[N];
int q[N];

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        int v, w, s; scanf("%d%d%d", &v, &w, &s);
        memcpy(g, f, sizeof f); // g是i-1的结果, f是当前要计算的
        for(int j = 0; j < v; j++)
        {
            int hh = 0, tt = -1;
            for(int k = j; k <= m; k += v)
            {
                if(hh <= tt && q[hh] < k - s * v) hh++; // 窗口大小如果超过s，弹出队头
                while(hh <= tt && g[q[tt]] + (k - q[tt]) / v * w <= g[k]) tt--; // 弹出元素
                q[++tt] = k; // 入队
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }
    
    printf("%d\n", f[m]);
    
    return 0;
}