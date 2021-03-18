#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    memset(b, 0x3f, sizeof b);
    for(int i = 1; i <= n; i++)
    {
        /*
        int l = 1, r = n + 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(b[mid] >= a[i]) r = mid;
            else l = mid + 1;
        }
        b[r] = a[i];
        //printf("%d %d ==> %d\n", i, a[i], r);
        */
        int t = lower_bound(b + 1, b + n + 1, a[i]) - b;
        b[t] = a[i];
    }
    
    int ans = lower_bound(b + 1, b + n + 1, 0x3f3f3f3f) - b - 1;
    
    printf("%d\n", ans);
    
    return 0;
}
