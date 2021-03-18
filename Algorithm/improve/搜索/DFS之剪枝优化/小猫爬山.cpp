// ����˳�򣺴Ӵ�Сö��
// �ų�����
// ���Ż������ڴ𰸷���
// �����ԣ����ܳ���W

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;

int n, w;
int a[N];
int g[N];
int ans = N;

void dfs(int u, int k) // ��ǰ��u�±�è��һ����k����
{
    if(k >= ans) return;
    if(u == n) 
    {
        ans = k;
        return;
    }
    
    for(int i = 0; i < k; i++)
    {
        if(g[i] + a[u] > w) continue;
        g[i] += a[u];
        dfs(u + 1, k);
        g[i] -= a[u];
    }
    
    g[k] = a[u];
    dfs(u + 1, k + 1);
    g[k] = 0;
}

int main()
{
    scanf("%d%d", &n, &w);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    sort(a, a + n);
    reverse(a, a + n);
    
    ans = n;
    dfs(0, 0);
    
    printf("%d\n", ans);
    
    return 0;
}
