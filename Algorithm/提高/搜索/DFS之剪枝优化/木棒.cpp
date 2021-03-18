// ����˳���ȷŴ�ģ���������
// �ų����ࣺ
// �����ԣ�ö��sum��Լ������һ������false�����һ������false�������ǰ�㲻�У��������ͬ���ȵĶ�����
// �����ԣ���С����ö��Լ��

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 70;

int g[N];
int a[N];
int n, sum, len;
bool st[N];

bool dfs(int k, int idx) // ����ÿ���鳢�����з����ķ���
{
    if(k * len == sum) return true;
    if(g[k] == len) return dfs(k + 1, 0);
    
    for(int i = idx; i < n; i++)
    {
        if(st[i] || g[k] + a[i] > len) continue;
        
        g[k] += a[i];
        st[i] = true;
        if(dfs(k, i + 1)) return true;
        g[k] -= a[i];
        st[i] = false;
        
        if(g[k] == 0) return false;
        if(g[k] + a[i] == len) return false;
        
        int j = i;
        while(j < n && a[j] == a[i]) j++; // ����������ͬ�ĵ�
        i = j - 1;
    }
    
    return false;
}

int main()
{
    while(scanf("%d", &n) && n)
    {
        sum = 0;
        for(int i = 0; i < n; i++) 
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        
        sort(a, a + n);
        reverse(a, a + n);
        
        memset(g, 0, sizeof g);
        memset(st, 0, sizeof st);
        
        len = 1;
        while(true)
        {
            if(sum % len == 0 && dfs(0, 0)) break;
            len++;
        }
        
        printf("%d\n", len);
    }
    
    return 0;
}
