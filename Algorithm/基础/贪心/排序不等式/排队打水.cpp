#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    sort(a, a + n);
    
    ll res = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
        res += a[i] * (n - 1 - i);
    }
    
    printf("%lld\n", res);
    
    return 0;
}
