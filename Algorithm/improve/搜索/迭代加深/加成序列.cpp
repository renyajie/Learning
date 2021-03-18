#include<iostream>
using namespace std;

const int N = 110;

int a[N];
int n;
bool st[N];

bool dfs(int u, int k)
{
    if(u == k) return a[u - 1] == n;
    
    bool st[N] = {0};
    
    for(int i = u - 1; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            int w = a[i] + a[j];
            if(w > n || w <= a[u - 1] || st[w]) continue;
            st[w] = true;
            a[u] = w;
            if(dfs(u + 1, k)) return true;
        }
    }
    
    return false;
}

int main()
{
    while(scanf("%d", &n) && n)
    {
        a[0] = 1;
        
        int depth = 1;
        while(depth <= n && !dfs(1, depth)) depth++;
        
        for(int i = 0; i < depth; i++) printf("%d ", a[i]);
        printf("\n");
    }
    
    return 0;
}
