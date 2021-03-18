#include<iostream>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    ll a1, m1;
    scanf("%lld%lld", &a1, &m1);
    
    bool flag = true;
    for(int i = 0; i < n - 1; i++)
    {
        ll a2, m2;
        scanf("%lld%lld", &a2, &m2);
        
        ll k1, k2;
        ll d = exgcd(a1, a2, k1, k2);
        if((m2 - m1) % d)
        {
            flag = false;
            break;
        }
        k1 = ((k1 * (m2 - m1) / d) % (a2 / d) + (a2 / d)) % (a2 / d);
        m1 = k1 * a1 + m1;
        a1 = a1 * a2 / d;
    }
    
    if(flag) printf("%lld\n", (m1 % a1 + a1) % a1);
    else printf("-1\n");
    
    return 0;
}
