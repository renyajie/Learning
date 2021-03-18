#include<iostream>
using namespace std;

const int N = 1010;

int a[N], up[N], down[N];

int main()
{
    int n; scanf("%d", &n);
    
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for(int i = 0; i < n; i++)
    {
        up[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[j] < a[i]) up[i] = max(up[i], up[j] + 1);
        }
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        down[i] = 1;
        for(int j = i; j < n; j++)
        {
            if(a[j] < a[i]) down[i] = max(down[i], down[j] + 1);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, up[i] + down[i] - 1);
    printf("%d\n", ans);
    
    return 0;
}
