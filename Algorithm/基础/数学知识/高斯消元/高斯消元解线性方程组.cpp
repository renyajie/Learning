#include<iostream>
#include<cmath>
using namespace std;

const int N = 110;
const double eps = 1e-5;

double a[N][N];
int n;

int gauss()
{
    int r, c;
    for(r = 0, c = 0; c < n; c++)
    {
        int t = r;
        for(int i = r + 1; i < n; i++)
        {
            if(a[i][c] > a[t][c]) t = i;
        }
        if(fabs(a[t][c]) < eps) continue;
        
        for(int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
        for(int i = n; i >= c; i--) a[r][i] /= a[r][c];
        for(int i = r + 1; i < n; i++)
        {
            for(int j = n; j >= c; j--)
            {
                a[i][j] -= a[i][c] * a[r][j];
            }
        }
        r++;
    }
    
    if(r < n)
    {
        for(int i = r; i < n; i++)
        {
            if(fabs(a[i][n]) > eps) return 2;
        }
        return 1;
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = i + 1; j < n; j++)
        {
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }
    
    int ans = gauss();
    
    if(ans == 2) printf("No solution\n");
    else if(ans == 1) printf("Infinite group solutions\n");
    else 
    {
        for(int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
    }
    
    return 0;
}
