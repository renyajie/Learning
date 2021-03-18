#include <cstdio>
#include <cstring>

using namespace std;

const int N = 55, M = 50050;

int f[N][M];

int dp(int a, int b)//a表示石子个数为1的所有可操作数，b表示石子个数大于1的可操作数
{
    int &v = f[a][b];
    if (v != -1) return v;
    if (!a) return v = b % 2;
    if (b == 1) return dp(a + 1, 0);

    if (a && !dp(a - 1, b)) return v = 1;
    if (b && !dp(a, b - 1)) return v = 1;
    if (a >= 2 && !dp(a - 2, b + (b ? 3 : 2))) return v = 1;
    if (a && b && !dp(a - 1, b + 1)) return v = 1;

    return v = 0;
}

int main()
{
    memset(f, -1, sizeof f);

    int T;
    scanf("%d", &T);
    while (T -- )
    {
        int n;
        scanf("%d", &n);
        int a = 0, b = 0;
        for (int i = 0; i < n; i ++ )
        {
            int x;
            scanf("%d", &x);
            if (x == 1) a ++ ;
            else b += b ? x + 1 : x;
        }

        if (dp(a, b)) puts("YES");
        else puts("NO");
    }

    return 0;
}
