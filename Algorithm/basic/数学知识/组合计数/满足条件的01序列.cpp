#include<iostream>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int qmi(int a, int b, int m)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = (ll)res * a % m;
        a = (ll)a * a % m;
        b >>= 1;
    }
    return res;
}

int C(int a, int b)
{
    int res = 1;
    for(int i = 1, j = a; i <= b; i++, j--)
    {
        res = (ll) res * j % mod;
        res = (ll) res * qmi(i, mod - 2, mod) % mod;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    printf("%d", (ll)C(2 * n, n) * qmi(n + 1, mod - 2, mod) % mod);
    
    return 0;
}
