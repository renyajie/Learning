#include<iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int res = 0;
    while(n--)
    {
        int x;
        scanf("%d", &x);
        
        res ^= x;
    }
    
    if(res) puts("Yes");
    else puts("No");
    
    return 0;
}

