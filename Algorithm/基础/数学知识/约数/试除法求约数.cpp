#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void get_divisor(int x)
{
    vector<int> res;
    
    for(int i = 1; i <= x / i; i++)
    {
        if(x % i == 0)
        {
            res.push_back(i);
            if(x / i != i) res.push_back(x / i);
        }
    }
    
    sort(res.begin(), res.end());
    for(int i : res) printf("%d ", i);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while(n--)
    {
        int x;
        scanf("%d", &x);
        
        get_divisor(x);
    }
    
    return 0;
}
