#include<iostream>
#include<cstring>
using namespace std;

const int N = 30;

int op[8][8] = 
{
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}
};

int a[30];
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};
int opposite[8] = {5, 4, 7, 6, 1, 0, 3, 2};
int path[100];

int f()
{
    int s[4];
    memset(s, 0, sizeof s);
    
    int ans = 0;
    for(int i = 0; i < 8; i++)
    {
        s[a[center[i]]]++;
    }
    for(int i = 1; i <= 3; i++) ans = max(ans, s[i]);
    return 8 - ans;
}

void operate(int u)
{
    int v = a[op[u][0]];
    for(int i = 0; i + 1 < 7; i++)
    {
        a[op[u][i]] = a[op[u][i + 1]];
    }
    a[op[u][6]] = v;
}

bool dfs(int u, int k, int last)
{
    if(u + f() > k) return false;
    if(u == k) return f() == 0;
    
    for(int i = 0; i < 8; i++)
    {
        if(last == opposite[i]) continue;
        
        operate(i);
        path[u] = i;
        if(dfs(u + 1, k, i)) return true;
        
        operate(opposite[i]);
    }
    
    return false;
}

int main()
{
    while(scanf("%d", &a[0]) && a[0])
    {
        for(int i = 1; i < 24; i++) scanf("%d", &a[i]);
        
        int depth = 0;
        
        while(!dfs(0, depth, -1)) depth++;
        
        if(depth == 0) printf("No moves needed");
        else 
        {
            for(int i = 0; i < depth; i++) printf("%c", path[i] + 'A');
            
        }
        printf("\n%d\n", a[center[0]]);
    }
    
    return 0;
}
