#include<iostream>
using namespace std;

typedef long long ll;

ll qmi(int a, int b, int c)
{
    ll res = 1, t = a;
    while(b)
    {
        if(b & 1) res = res * t % c;
        t = t * t % c;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while(n--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        
        printf("%lld\n", qmi(a, b, c));
    }
    
    return 0;
}
