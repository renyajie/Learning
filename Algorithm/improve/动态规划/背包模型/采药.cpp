#include<iostream>
using namespace std;

const int N = 1010;

int f[N];

int main()
{
    int m, n; scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++)
    {
        int v, w; scanf("%d%d", &v, &w);
        for(int j = m; j >= v; j--)
        {
            f[j] = max(f[j], f[j - v] + w);
        }
    }
    
    printf("%d\n", f[m]);
    
    return 0;
}
