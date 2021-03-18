// 搜索顺序：从可选数字最少的位置开始枚举，这里根据位运算 判断row[x] && col[y] && a[x / 3][y / 3]，1代表可选状态，求最少的1
// 排序冗余：根据可选状态依次枚举
// 可行性：（和当前行列矛盾去掉）
// 最优性：

#include<iostream>
using namespace std;

const int N = 9;

int ones[1 << N];
int b2n[1 << N];
char g[100];
int row[10], col[10], mat[10][10];
int cnt;


void set_st(int x, int y, int t, bool add) // t从0开始
{
    if(add) g[x * 9 + y] = '1' + t;
    else g[x * 9 + y] = '.';
    
    int v = 1 << t;
    
    if(add) v = -v;
    
    row[x] += v;
    col[y] += v;
    mat[x / 3][y / 3] += v;
    
    
}

int lowbit(int x)
{
    return x & -x;
}

void find(int &a, int &b)
{
    int x = -1, y = -1;
    int sum = 10;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(g[i * 9 + j] != '.') continue;
            int t = row[i] & col[j] & mat[i / 3][j / 3];
            if(ones[t] < sum)
            {
                sum = ones[t];
                x = i, y = j;
            }
        }
    }
    a = x, b = y;
}

bool dfs(int x, int y)
{
    if(cnt == 0) return true;
    
    int st = row[x] & col[y] & mat[x / 3][y / 3];
    
    
    for(int i = st; i; i -= lowbit(i))
    {
        int t = b2n[lowbit(i)];
        
        cnt--;
        set_st(x, y, t, true);
        
        int a = -1, b = -1;
        find(a, b);
        if(dfs(a, b)) return true;
        
        set_st(x, y, t, false);
        cnt++;
    }
    
    return false;
}

int main()
{
    for(int i = 0; i < 1 << N; i++)
    {
        for(int j = i; j; j -= lowbit(j))
        {
            ones[i]++;
        }
    }
    
    for(int i = 0; i < 9; i++) b2n[1 << i] = i;
    
    
    while(scanf("%s", g) && g[0] != 'e')
    {
        for(int i = 0; i < 9; i++) col[i] = row[i] = (1 << N) - 1;
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                mat[i][j] = (1 << N) - 1;
            }
        }
        
        cnt = 0;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                char c = g[i * 9 + j];
                if(c != '.')
                {
                    set_st(i, j, c - '1', true);
                }
                else cnt++;
            }
        }
        
        int x = -1, y = -1;
        find(x, y);
        
        if(x != -1) dfs(x, y);
        
        printf("%s\n", g);
    }
    
    return 0;
}
