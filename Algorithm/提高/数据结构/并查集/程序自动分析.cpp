#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int N = 1e6 + 10;

struct Query
{
    int a, b, e;
}query[N];
int n;
int p[2 * N];
unordered_map<int,int> mp;

int get(int x)
{
    if(mp.count(x) == 0) mp[x] = ++n;
    return mp[x];
}

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        mp.clear();
        n = 0;
        
        int m; scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            int a, b, e; scanf("%d%d%d", &a, &b, &e);
            query[i] = {get(a), get(b), e};
        }
        
        for(int i = 1; i <= n; i++) p[i] = i;
        for(int i = 0; i < m; i++)
            if(query[i].e == 1) p[find(query[i].a)] = find(query[i].b);
        
        bool ok = true;
        for(int i = 0; i < m; i++)
            if(query[i].e == 0 && find(query[i].a) == find(query[i].b))
            {
                ok = false; break;
            }
        
        puts(ok ? "YES" : "NO");
    }
    
    return 0;
}
