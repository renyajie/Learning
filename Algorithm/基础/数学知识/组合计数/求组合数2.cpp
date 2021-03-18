#include<iostream>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10, mod = 1e9 + 7;

int fact[N], infact[N];

int qmi(int a, int b, int m)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = (ll) res * a % m;
        a = (ll)a * a % m;
        b >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i++)
    {
        fact[i] = (ll)fact[i - 1] * i % mod; 
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

int main()
{
    init();
    
    int n;
    scanf("%d", &n);
    
    while(n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        
        printf("%d\n", (ll)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }
    
    return 0;
}
