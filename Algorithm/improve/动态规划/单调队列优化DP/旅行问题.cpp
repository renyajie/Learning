#include<iostream>
using namespace std;

const int N = 1e6 + 10, M = 2 * N;

typedef long long ll;

int q[M];
int o[M], d[M];
ll s[M];
ll dp[M];
bool st[N];

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &o[i], &d[i]);
        o[i + n] = o[i];
        d[i + n] = d[i];
    }
    
    for(int i = 1; i <= 2 * n; i++) s[i] = s[i - 1] + o[i - 1] - d[i - 1]; // ˳ʱ���ߵ�վ��iʣ�������
    
    int hh = 0, tt = -1;
    for(int i = 2 * n; i >= 1; i--)
    {
        if(hh <= tt && q[hh] > i + n) hh++;
        if(i <= n)
        {
            if(s[i] <= s[q[hh]]) st[i] = true; // �ڶ����ߵ�iʱ�������е���Сֵ(s[q[hh]])Ҫ�ȴ�i��ʼ������s[i]��
        }
        
        while(hh <= tt && s[q[tt]] >= s[i]) tt--;
        q[++tt] = i;
    }
    
    
    for(int i = 2 * n; i >= 1; i--) s[i] = s[i + 1] + o[i + 1] - d[i]; // ��ʱ���ߵ�վ��iʱʣ�������
    
    hh = 0, tt = -1;
    for(int i = 1; i <= 2 * n; i++) 
    {
        if(hh <= tt && q[hh] < i - n) hh++;
        if(i > n)
        {
            if(s[i] <= s[q[hh]]) st[i - n] = true; // �ڶ����ߵ�iʱ�������е���Сֵ(s[q[hh]])Ҫ�ȴ�i��ʼ������s[i]Ҫ��
        }
        while(hh <= tt && s[q[tt]] >= s[i]) tt--;
        q[++tt] = i;
        
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(st[i]) puts("TAK");
        else puts("NIE");
    }
    
    return 0;
}
