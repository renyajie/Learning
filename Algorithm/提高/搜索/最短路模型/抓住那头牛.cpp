#include<iostream>
#include<cstring>
using namespace std;

const int N = 2e5 + 10;

int n, k;
int q[N];
int dis[N];

int bfs()
{
    int hh = 0, tt = -1;
    q[++tt] = n;
    memset(dis, -1, sizeof dis);
    dis[n] = 0;
    
    while(hh <= tt)
    {
        int p = q[hh++];
        if(p == k) return dis[p];
        
        if(p - 1 >= 0 && dis[p - 1] == -1)
        {
            q[++tt] = p - 1;
            dis[p - 1] = dis[p] + 1;
        }
        if(p + 1 < N && dis[p + 1] == -1)
        {
            q[++tt] = p + 1;
            dis[p + 1] = dis[p] + 1;
        }
        if(p * 2 < N && dis[p * 2] == -1)
        {
            q[++tt] = p * 2;
            dis[p * 2] = dis[p] + 1;
        }
    }
    
    return -1;
}

int main()
{
    scanf("%d%d", &n, &k);
    
    printf("%d\n", bfs());
    
    return 0;
}
