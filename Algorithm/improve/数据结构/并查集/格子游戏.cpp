#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 40010;

int p[N];
int n, m;

int get(int a, int b)
{
    return (a - 1) * n + b - 1;
}

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i < N; i++) p[i] = i;
    
    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        char s[3];
        int a, b; scanf("%d%d%s", &a, &b, s);
        
        int x = get(a, b), y;
        if(s[0] == 'D') y = get(a + 1, b);
        else y = get(a, b + 1);
        
        int px = find(x), py = find(y);
        if(px != py) p[px] = py;
        else { ans = i; break; }
    }
    
    if(!ans) printf("draw\n");
    else printf("%d\n", ans);
    
    return 0;
}
