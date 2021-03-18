#include<iostream>
using namespace std;

const int N = 110;

int a[N][N];
int n;

int gauss()
{
    int r, c;
    for(c = 0, r = 0; c < n; c++)
    {
        int t = r;
        for(int i = r + 1; i < n; i++)
        {
            if(a[i][c] > a[t][c]) 
            {
                t = i;
                break;
            }
        }
        if(a[t][c] == 0) continue;
        
        for(int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
        for(int i = r + 1; i < n; i++)
        {
            if(a[i][c] == 0) continue;
            for(int j = n; j >= c; j--) a[i][j] = a[i][j] ^ a[r][j];
        }
        r++;
    }
    
    if(r < n)
    {
        for(int i = r; i < n; i++)
        {
            if(a[i][n]) return 2;
        }
        return 1;
    }
    
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i][j])
            {
                a[i][n] ^= a[j][n];
            }
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
            scanf("%d", &a[i][j]);
        }
    }
    
    int ans = gauss();
    
    if(ans == 2) printf("No solution\n");
    else if(ans == 1) printf("Multiple sets of solutions\n");
    else 
    {
        for(int i = 0; i < n; i++) printf("%d\n", a[i][n]);
    }
    
    return 0;
}
