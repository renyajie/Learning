#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;

const int N = 110;
int n;
int f[N];

int sg(int x)
{
    if(f[x] != -1) return f[x];
    
    unordered_set<int> num;
    for(int i = 0; i < x; i++) // 根据题意计算SG值即可
    {
        for(int j = 0; j <= i; j++)
        {
            num.insert(sg(i) ^ sg(j)); // 多个独立局面的总SG=各独立的SG异或和
        }
    }
    
    int res;
    for(int i = 0;;i++)
    {
        if(!num.count(i))
        {
            res = i;
            break;
        }
    }
    return f[x] = res;
}

int main()
{
    scanf("%d", &n);
    
    memset(f, -1, sizeof f);
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        
        res ^= sg(x); // 计算每个局面的SG值
    }
    
    if(res) puts("Yes"); // 若异或结果不为0，先手总能将异或0的局面给后手，转化为NIM游戏，先手必胜
    else puts("No");
    
    return 0;
}
