#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;

struct Range
{
    int l, r;
    
    bool operator < (const Range &W) const
    {
        return r < W.r;
    }
} range[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }
    
    sort(range, range + n);
    int res = 0, ed = -2e9;
    for(int i = 0; i < n; i++)
    {
        if(range[i].l > ed)
        {
            ed = range[i].r;
            res++;
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}
