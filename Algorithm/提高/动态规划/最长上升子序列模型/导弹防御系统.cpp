#include<iostream>
using namespace std;

const int N = 60;

int a[N];
int up[N], down[N];
int n;

bool dfs(int depth, int cur, int su, int sd)
{
    if(su + sd > depth) return false;
    if(cur == n) return true;
    
    bool flag = false;
    
    // 下降序列
    int k = 0;
    while(k < su && down[k] <= a[cur]) k++;
    int pre = down[k];
    down[k] = a[cur];
    if(k >= su) flag = flag || dfs(depth, cur + 1, su + 1, sd);
    else flag = flag || dfs(depth, cur + 1, su, sd);
    down[k] = pre;
    
    if(flag) return true;
    
    // 上升序列
    k = 0;
    while(k < sd && up[k] >= a[cur]) k++;
    pre = up[k];
    up[k] = a[cur];
    if(k >= sd) flag = flag || dfs(depth, cur + 1, su, sd + 1);
    else flag = flag || dfs(depth, cur + 1, su, sd);
    up[k] = pre;
    
    return flag;
}

int main()
{
    while(cin >> n, n)
    {
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        
        int depth = 0;
        while(!dfs(depth, 0, 0, 0)) depth++;
        printf("%d\n", depth);
    }
    
    
    return 0;
}
