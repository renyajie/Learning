// ״̬��ʾ��
// 1. ���ϣ� f[i][j]����ǰi�����֣���ʾ��j�ķ���
// 2. ���ԣ�����
// ״̬���㣺
// f[i][j] = f[i - 1][j] + sigma{f[i - 1][j - k * i], k >= 1}
// f[i][j - i] = sigma{f[i - 1][j - k * i], k >= 1}
// f[i][j] = f[i - 1][j] + f[i][j - i]
// �����Ż� f[j] = f[j] + f[j - i]

#include<iostream>
using namespace std;

const int N = 1010, mod = 1e9 + 7;

int f[N];

int main()
{
    int n;
    scanf("%d", &n);
    
    f[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            f[j] = (f[j] + f[j - i]) % mod;
        }
    }
    
    printf("%d\n", f[n]);
    
    return 0;
}
