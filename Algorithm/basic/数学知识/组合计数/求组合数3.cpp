#include<iostream>
using namespace std;

typedef long long ll;

int p;

ll qmi(ll a, ll b, int p)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int C(ll a, ll b)
{
    int res = 1;
    for(int i = 1, j = a; i <= b; i++, j--)
    {
        res = (ll)res * j % p;
        res = (ll)res * qmi(i, p - 2, p) % p;
    }
    return res;
}

int lucas(ll a, ll b)
{
    if(a < p && b < p) return C(a, b);
    return (ll)lucas(a % p, b % p) * lucas(a / p, b / p) % p;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while(n--)
    {
        ll a, b;
        scanf("%lld%lld%d", &a, &b, &p);
        
        printf("%d\n", lucas(a, b));
    }
    
    return 0;
}
