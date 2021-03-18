// b, m ���ʣ���b x = 1 (mod m), ��x��b mod m����Ԫ
// ��mΪ���������ݷ�����x b = b ^ (m - 1)����x = b ^ (m - 2)
// ��mΪ������ b x = 1 (mod m) �ȼ��� b x + a m = 1������չŷ�������x

// ע�⣺��b �� m�ı�������b x % m = 0��b mod m����Ԫ������

#include<iostream>
using namespace std;

typedef long long ll;

ll qmi(int a, int b, int c)
{
    ll res = 1, t = a;
    while(b)
    {
        if(b & 1) res = res * t % c;
        t = t * t % c;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while(n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        
        if(a % b == 0) puts("impossible");
        else printf("%lld\n", qmi(a, b - 2, b));
    }
    
    return 0;
}
