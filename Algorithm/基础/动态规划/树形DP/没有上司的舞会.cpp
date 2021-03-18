#include<iostream>
#include<cstring>
using namespace std;

const int N = 6010;

int h[N], e[N], ne[N], idx;
int happy[N];
int has_father[N];
int f[N][2];
int n;

void init()
{
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dp(int root, int st)
{
    int &v = f[root][st];
    if(v != -1000000000) return v;
    if(st == 1) v = happy[root];
    else v = 0;
    for(int i = h[root]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(st == 1) v += dp(j, 0);
        else v += max(dp(j, 1), dp(j, 0));
    }
    return v;
}

int main()
{
    init();
    
    memset(has_father, -1, sizeof has_father);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &happy[i]);
    for(int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(b, a);
        has_father[a] = b;
    }
    
    int root = 1;
    while(has_father[root] != -1) root = has_father[root];
    
    //printf("%d\n", root);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            f[i][j] = -1000000000;
        }
    }
    int ans = max(dp(root, 0), dp(root, 1));
    
    printf("%d\n", ans);
    
    return 0;
}
