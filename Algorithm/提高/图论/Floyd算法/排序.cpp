#include<iostream>
#include<cstring>
using namespace std;

const int N = 30;

int dist[N][N];
int n, m;
bool st[N];

void floyd()
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dist[i][j] |= dist[i][k] && dist[k][j];
            }
        }
    }
}

char get_min()
{
    int t = 0;
    for(int i = 0; i < n; i++)
    {
        if(st[i]) continue;
        bool flag = true;
        for(int j = 0; j < n; j++)
        {
            if(!st[j] && dist[j][i]) // 在目前未确定的，可以走到i，说明i不是最小元素
            {
                flag = false;
                break;
            }
        }
        if(flag) 
        {
            t = i;
            st[i] = true;
            break;
        }
    }
    return char(t + 'A');
}

int check()
{
    for(int i = 0; i < n; i++)
    {
        if(dist[i][i]) return 1;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++) // 找不一样的点对，防止判断dist[i][i]
        {
            if(!dist[i][j] && !dist[j][i]) return 2;
        }
    }
    
    return 0;
}

int main()
{
    while(scanf("%d%d", &n, &m) == 2 && (n && m))
    {
        memset(dist, 0, sizeof dist);
        memset(st, 0, sizeof st);
        
        int cnt = 0, type = 2;
        for(int i = 0; i < m; i++)
        {
            char s[5]; scanf("%s", s);
            int a = s[0] - 'A', b = s[2] - 'A';
            
            if(type == 2) //0 = 拍好，1 = 矛盾， 2 = 无法确定
            {
                dist[a][b] = 1;
                floyd();
                type = check();
                cnt++;
            }
        }
        
        if(type == 0)
        {
            printf("Sorted sequence determined after %d relations: ", cnt);
            for(int i = 0; i < n; i++) printf("%c", get_min());
            printf(".\n");
        }
        else if(type == 1)
        {
            printf("Inconsistency found after %d relations.\n", cnt);
        }
        else
        {
            printf("Sorted sequence cannot be determined.\n");
        }
    }
    
    return 0;
}
