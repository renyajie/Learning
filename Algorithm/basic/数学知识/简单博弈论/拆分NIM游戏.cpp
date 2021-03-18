#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;

const int N = 110;
int n;
int f[N];

int sg(int x)
{
    if(f[x] != -1) return f[x];
    
    unordered_set<int> num;
    for(int i = 0; i < x; i++) // �����������SGֵ����
    {
        for(int j = 0; j <= i; j++)
        {
            num.insert(sg(i) ^ sg(j)); // ��������������SG=��������SG����
        }
    }
    
    int res;
    for(int i = 0;;i++)
    {
        if(!num.count(i))
        {
            res = i;
            break;
        }
    }
    return f[x] = res;
}

int main()
{
    scanf("%d", &n);
    
    memset(f, -1, sizeof f);
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        
        res ^= sg(x); // ����ÿ�������SGֵ
    }
    
    if(res) puts("Yes"); // ���������Ϊ0���������ܽ����0�ľ�������֣�ת��ΪNIM��Ϸ�����ֱ�ʤ
    else puts("No");
    
    return 0;
}
