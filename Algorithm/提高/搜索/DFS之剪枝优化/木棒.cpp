// 搜索顺序：先放大的，降序排序
// 排除冗余：
// 可行性：枚举sum的约数、第一个不行false、最后一个不行false、如果当前点不行，则后面相同长度的都不行
// 最优性：从小到大枚举约数

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 70;

int g[N];
int a[N];
int n, sum, len;
bool st[N];

bool dfs(int k, int idx) // 对于每个组尝试所有放满的方案
{
    if(k * len == sum) return true;
    if(g[k] == len) return dfs(k + 1, 0);
    
    for(int i = idx; i < n; i++)
    {
        if(st[i] || g[k] + a[i] > len) continue;
        
        g[k] += a[i];
        st[i] = true;
        if(dfs(k, i + 1)) return true;
        g[k] -= a[i];
        st[i] = false;
        
        if(g[k] == 0) return false;
        if(g[k] + a[i] == len) return false;
        
        int j = i;
        while(j < n && a[j] == a[i]) j++; // 跳过后面相同的点
        i = j - 1;
    }
    
    return false;
}

int main()
{
    while(scanf("%d", &n) && n)
    {
        sum = 0;
        for(int i = 0; i < n; i++) 
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        
        sort(a, a + n);
        reverse(a, a + n);
        
        memset(g, 0, sizeof g);
        memset(st, 0, sizeof st);
        
        len = 1;
        while(true)
        {
            if(sum % len == 0 && dfs(0, 0)) break;
            len++;
        }
        
        printf("%d\n", len);
    }
    
    return 0;
}
