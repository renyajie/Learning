#include<iostream>
using namespace std;

const int N = 1010;

int row_max[N][N], row_min[N][N];
int w[N][N];
int q[N];
int a, b, n;

void get_min(int u[], int v[], int total)
{
    int hh = 0, tt = -1;
    for(int i = 1; i <= total; i++)
    {
        if(hh <= tt && q[hh] <= i - n) hh++;
        while(hh <= tt && u[q[tt]] >= u[i]) tt--;
        q[++tt] = i;
        v[i] = u[q[hh]];
    }
}

void get_max(int u[], int v[], int total)
{
    int hh = 0, tt = -1;
    for(int i = 1; i <= total; i++)
    {
        if(hh <= tt && q[hh] <= i - n) hh++;
        while(hh <= tt && u[q[tt]] <= u[i]) tt--;
        q[++tt] = i;
        v[i] = u[q[hh]];
    }
}

int main()
{
    scanf("%d%d%d", &a, &b, &n);
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }
    
    for(int i = 1; i <= a; i++)
    {
        get_min(w[i], row_min[i], b);
        get_max(w[i], row_max[i], b);
    }
    
    //for(int i = 1; i <= b; i++) printf("%d ", row_max[2][i]);
    //printf("\n");
    
    int col_min[N], col_max[N], col[N];
    int ans = 1e9;
    for(int i = n; i <= b; i++)
    {
        for(int j = 1; j <= a; j++) col[j] = row_min[j][i];
        get_min(col, col_min, a);
        
        for(int j = 1; j <= a; j++) col[j] = row_max[j][i];
        get_max(col, col_max, a);
        
        for(int j = n; j <= a; j++) ans = min(ans, col_max[j] - col_min[j]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}
