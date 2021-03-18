#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 30010;

int p[N], d[N], sz[N];
int n, m;

int find(int x)
{
    if(p[x] != x) 
    {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}

int main()
{
    scanf("%d", &m);
    for(int i = 0; i < N; i++) p[i] = i, sz[i] = 1;
    for(int i = 0; i < m; i++)
    {
        char s[2]; int a, b;
        scanf("%s%d%d", s, &a, &b);
        int pa = find(a), pb = find(b);
        if(s[0] == 'M')
        {
            if(pa != pb) p[pa] = pb, d[pa] = sz[pb], sz[pb] += sz[pa];
        }
        else
        {
            if(pa != pb) printf("-1\n");
            else printf("%d\n", max(0, abs(d[a] - d[b]) - 1));
        }
    }
    
    return 0;
}
