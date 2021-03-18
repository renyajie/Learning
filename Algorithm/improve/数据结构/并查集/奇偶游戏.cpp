#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int N = 10010;

int p[N], d[N];
int n, m;
unordered_map<int,int> mp;

int get(int x)
{
    if(!mp.count(x)) mp[x] = ++n;
    return mp[x];
}

int find(int x)
{
    if(p[x] != x)
    {
        int root = find(p[x]);
        d[x] = (d[x] + d[p[x]]) % 2; // 带权并查集，维护和根的距离
        p[x] = root;
    }
    return p[x];
}

int main()
{
    int len; scanf("%d%d", &len, &m);
    for(int i = 0; i < N; i++) p[i] = i;
    int ans = m;
    for(int i = 1; i <= m; i++)
    {
        char s[6];
        int a, b; scanf("%d%d%s", &a, &b, s);
        a = get(a - 1), b = get(b);
        int pa = find(a), pb = find(b);
        if(s[0] == 'e')
        {
            if(pa == pb && (d[a] + d[b]) % 2) 
            {
                ans = i - 1; break;
            }
            else if(pa != pb)
            {
                p[pa] = pb;
                d[pa] = ((2 - d[a] - d[b]) % 2 + 2) % 2;
            }
        }
        else
        {
            if(pa == pb && (d[a] + d[b]) % 2 == 0) 
            {
                ans = i - 1; break;
            }
            else if(pa != pb)
            {
                p[pa] = pb;
                d[pa] = ((1 - d[a] - d[b]) % 2 + 2) % 2;
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
