#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

const int N = 19;
const double eps = 1e-8;

typedef pair<double,double> pdd;

int dp[1 << N];
int tran[N][N];
pdd point[N];

int cmp(double a, double b)
{
    if(fabs(a - b) < eps) return 0;
    if(a < b) return -1;
    return 1;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            double x, y; scanf("%lf%lf", &x, &y);
            point[i] = {x, y};
        }
        
        memset(tran, 0, sizeof tran);
        for(int i = 0; i < n; i++)
        {
            tran[i][i] = 1 << i;
            for(int j = 0; j < n; j++)
            {
                double x1 = point[i].first, y1 = point[i].second;
                double x2 = point[j].first, y2 = point[j].second;
                if(!cmp(x1, x2)) continue;
                double a = (y1 / x1 - y2 / x2) / (x1 - x2);
                double b = (y1 / x1) - a * x1;
                if(cmp(a, 0) >= 0) continue;
                
                for(int k = 0; k < n; k++)
                {
                    double x3 = point[k].first, y3 = point[k].second;
                    if(!cmp(a * x3 * x3 + b * x3, y3))
                    {
                        tran[i][j] += 1 << k;
                    }
                }
            }
        }
        
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for(int i = 0; i + 1 < 1 << n; i++)
        {
            int x;
            for(int j = 0; j < n; j++)
            {
                if(!(i >> j & 1))
                {
                    x = j;
                    break;
                }
            }
            
            for(int j = 0; j < n; j++)
            {
                dp[i | tran[x][j]] = min(dp[i | tran[x][j]], dp[i] + 1);
            }
        }
        
        printf("%d\n", dp[(1 << n) - 1]);
    }
    
    return 0;
}
