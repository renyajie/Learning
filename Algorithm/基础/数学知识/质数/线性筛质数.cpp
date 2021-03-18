#include<iostream>
using namespace std;

const int N = 1e6 + 10;

int prime[N], cnt;
bool st[N];
int n;

void get_prime()
{
    for(int i = 2; i <= n; i++)
    {
        if(!st[i]) prime[cnt++] = i;
        for(int j = 0; prime[j] <= n / i; j++)
        {
            st[prime[j] * i] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int main()
{
    scanf("%d", &n);
    
    get_prime();
    
    printf("%d", cnt);
    
    return 0;
}
