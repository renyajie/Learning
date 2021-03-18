#include<iostream>
#include<vector>
using namespace std;

const int N = 5010;

int prime[N], cnt;
bool st[N];
int sum[N];

void get_prime(int n)
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

int get(int n, int p)
{
    int res = 0;
    while(n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> &a, int b)
{
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    
    while(t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    
    get_prime(a);
    
    for(int i = 0; i < cnt; i++)
    {
        int p = prime[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }
    
    vector<int> res;
    res.push_back(1);
    
    for(int i = 0; i < cnt; i++)
    {
        for(int j = 0; j < sum[i]; j++)
        {
            res = mul(res, prime[i]);
        }
    }
    
    for(int i = res.size() - 1; i >= 0; i--) printf("%d", res[i]);
    
    return 0;
}
