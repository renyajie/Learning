#include<iostream>
using namespace std;

typedef long long ll;

const int N = 20;

int prime[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d", &prime[i]);
    
    int res = 0;
    for(int i = 1; i < 1 << m; i++)
    {
        ll t = 1;
        int cnt = 0;
        bool flag = true;
        for(int j = 0; j < m; j++)
        {
            if(i >> j & 1)
            {
                cnt++;
                t *= prime[j];
                if(t > n)
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag)
        {
            if(cnt & 1) res += n / t;
            else res -= n / t;
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}
