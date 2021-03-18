// 搜索顺序：从大到小枚举
// 排除冗余
// 最优化：大于答案返回
// 可行性：不能超过W

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;

int n, w;
int a[N];
int g[N];
int ans = N;

void dfs(int u, int k) // 当前第u下标猫，一共有k辆车
{
    if(k >= ans) return;
    if(u == n) 
    {
        ans = k;
        return;
    }
    
    for(int i = 0; i < k; i++)
    {
        if(g[i] + a[u] > w) continue;
        g[i] += a[u];
        dfs(u + 1, k);
        g[i] -= a[u];
    }
    
    g[k] = a[u];
    dfs(u + 1, k + 1);
    g[k] = 0;
}

int main()
{
    scanf("%d%d", &n, &w);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    sort(a, a + n);
    reverse(a, a + n);
    
    ans = n;
    dfs(0, 0);
    
    printf("%d\n", ans);
    
    return 0;
}
