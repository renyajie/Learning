#include<cstring>
#include<iostream>
using namespace std;

const int N = 20010;

int g[N], f[N];
int q[N];

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        int v, w, s; scanf("%d%d%d", &v, &w, &s);
        memcpy(g, f, sizeof f); // g��i-1�Ľ��, f�ǵ�ǰҪ�����
        for(int j = 0; j < v; j++)
        {
            int hh = 0, tt = -1;
            for(int k = j; k <= m; k += v)
            {
                if(hh <= tt && q[hh] < k - s * v) hh++; // ���ڴ�С�������s��������ͷ
                while(hh <= tt && g[q[tt]] + (k - q[tt]) / v * w <= g[k]) tt--; // ����Ԫ��
                q[++tt] = k; // ���
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }
    
    printf("%d\n", f[m]);
    
    return 0;
}