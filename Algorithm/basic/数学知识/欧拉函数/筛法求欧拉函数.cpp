#include<iostream>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int prime[N], cnt;
bool st[N];
int euler[N];
int n;

void get_euler()
{
    euler[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!st[i])
        {
            prime[cnt++] = i;
            euler[i] = i - 1;
        }
        for(int j = 0; prime[j] <= n / i; j++)
        {
            int t = prime[j] * i;
            st[t] = true;
            if(i % prime[j] == 0)
            {
                euler[t] = euler[i] * prime[j];
                break;
            }
            euler[t] = euler[i] * (prime[j] - 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    
    get_euler();
    
    ll res = 0;
    for(int i = 1; i <= n; i++) res += euler[i];
    printf("%lld", res);
    
    return 0;
}
