#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;

struct Range
{
    int l, r;
    
    bool operator < (const Range & W) const
    {
        return l < W.l;
    }
} range[N];

int main()
{
    int st, ed;
    scanf("%d%d", &st, &ed);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);
    
    int res = 0;
    bool flag = true;
    
    for(int i = 0, j = 0; i < n; i++)
    {
        int cover = -2e9;
        while(j < n && range[j].l <= st)
        {
            cover = max(cover, range[j].r);
            j++;
        }
        
        if(cover < st)
        {
            res = -1;
            break;
        }
        
        res++;
        st = cover;
        
        //printf("j = %d, res = %d, st = %d\n", j, res, st);
        if(st >= ed)
        {
            break;
        }
        
        i = j - 1;
    }
    
    if(st < ed) res = -1;
    printf("%d\n", res);
    
    return 0;
}
