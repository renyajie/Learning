#include<iostream>
#include<unordered_map>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

unordered_map<int,int> prime;

void get_prime(int x)
{
    for(int i = 2; i <= x / i; i++)
    {
        while(x % i == 0)
        {
            x /= i;
            prime[i]++;
        }
    }
    if(x > 1) prime[x]++;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while(n--)
    {
        int x;
        scanf("%d", &x);
        
        get_prime(x);
    }
    
    ll res = 1;
    for(auto p : prime)
    {
        res = res * (p.second + 1) % mod;
    }
    
    printf("%lld\n", res);
    
    return 0;
}
