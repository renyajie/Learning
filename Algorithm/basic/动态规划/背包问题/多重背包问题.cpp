#include<iostream>
using namespace std;

const int N = 710;

int v[N], w[N];
int f[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int k = 1;
        while(k <= c)
        {
            cnt++;
            v[cnt] = k * a;
            w[cnt] = k * b;
            c -= k;
            k <<= 1;
        }
        if(c > 0)
        {
            cnt++;
            v[cnt] = c * a;
            w[cnt] = c * b;
        }
    }
    
    n = cnt;
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    
    printf("%d\n", f[m]);
    
    return 0;
}
