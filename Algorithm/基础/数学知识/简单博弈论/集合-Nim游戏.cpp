#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;

const int N = 110, M = 10010;

int n, k;
int s[N], f[M];

int sg(int h)
{
    if(f[h] != -1) return f[h];
    
    unordered_set<int> num;
    for(int i = 0; i < k; i++)
    {
        if(h >= s[i]) num.insert(sg(h - s[i]));
    }
    
    int res;
    for(int i = 0;;i++)
    {
        if(!num.count(i)) 
        {
            res = i;
            break;
        }
    }
    return f[h] = res;
}

int main()
{
    scanf("%d", &k);
    for(int i = 0; i < k; i++) scanf("%d", &s[i]);
    
    scanf("%d", &n);
    memset(f, -1, sizeof f);
    int res = 0;
    
    for(int i = 0; i < n; i++)
    {
        int h;
        scanf("%d", &h);
        
        res ^= sg(h);
    }
    
    if(res) puts("Yes");
    else puts("No");
    
    return 0;
}
