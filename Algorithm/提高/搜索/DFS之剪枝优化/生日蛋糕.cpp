// 思路：枚举R和H
// 搜索顺序：从大到小，先R后H
// 排除冗余：
// 可行性：cur_v + minv[i] > V := false、cur_s + mins[i] >= ans := false、s + 2 / r_{k + 1} * (N - V) >= ans := false

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int M = 30, INF = 1000000000;

int minv[M], mins[M];
int n, m;
int R[M], H[M];
int ans = INF;

void dfs(int u, int s, int v) // 第几层蛋糕、目前的表面积、目前的体积
{
    if(v + minv[u] > n) return;
    if(s + mins[u] >= ans) return;
    if(s + 2 * (n - v) / R[u + 1] >= ans) return;
    
    if(!u)
    {
        if(v == n) ans = s;
        return;
    }
    
    for(int r = min(R[u + 1] - 1, (int)sqrt(n - v)); r >= u; r--)
    {
        for(int h = min(H[u + 1] - 1, (n - v) / r / r); h >= u; h--)
        {
            int t = 0;
            R[u] = r, H[u] = h;
            if(u == m) t += r * r;
            t += 2 * r * h;
            dfs(u - 1, s + t, v + r * r * h);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) 
    {
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }
    
    R[m + 1] = H[m + 1] = INF;
    dfs(m, 0, 0);
    
    if(ans == INF) ans = 0;
    printf("%d\n", ans);
    
    return 0;
}
