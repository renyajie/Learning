#include<iostream>
#include<cstring>
using namespace std;

const int N = 20;

int a[N];
int op[5][N];
int n;

int f()
{
    int cnt = 0;
    for(int i = 0; i + 1 < n; i++)
    {
        if(a[i] + 1 != a[i + 1])
        {
            cnt++;
        }
    }
    
    return (cnt + 2) / 3;
}


bool dfs(int u, int k)
{
    if(u + f() > k) return false;
    if(u == k) return f() == 0;
    
    
    for(int len = 1; len <= n; len++)
    {
        for(int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            for(int q = j + 1; q < n; q++)
            {
                memcpy(op[u], a, sizeof a);
                
                //printf("len: %d, i: %d, q: %d\n", len, i, q);
                //for(int i = 0; i < 5; i++) printf("%d ", a[i]);
                //printf("\n");
                int y = i;
                for(int p = j + 1; p <= q; p++, y++) a[y] = op[u][p];
                for(int p = y, x = i; x <= j; p++, x++) a[p] = op[u][x];
                
                //for(int i = 0; i < 5; i++) printf("%d ", a[i]);
                //printf("\n");
                
                //exit(0);
                
                if(dfs(u + 1, k)) return true;
                memcpy(a, op[u], sizeof a);
            }
            
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        
        int depth = 0;
        while(depth < 5 && !dfs(0, depth)) depth++;
        
        if(depth == 5) printf("5 or more\n");
        else printf("%d\n", depth);
    }
    
    return 0;
}
