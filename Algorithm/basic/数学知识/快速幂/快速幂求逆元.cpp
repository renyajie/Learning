// b, m 互质，若b x = 1 (mod m), 则x是b mod m的逆元
// 当m为质数，根据费马定理，x b = b ^ (m - 1)，故x = b ^ (m - 2)
// 当m为合数， b x = 1 (mod m) 等价于 b x + a m = 1，用拓展欧几里得求x

// 注意：若b 是 m的倍数，则b x % m = 0，b mod m的逆元不存在

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
        int a, b;
        scanf("%d%d", &a, &b);
        
        if(a % b == 0) puts("impossible");
        else printf("%lld\n", qmi(a, b - 2, b));
    }
    
    return 0;
}
