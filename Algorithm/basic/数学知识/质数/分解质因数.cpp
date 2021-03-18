#include<iostream>
using namespace std;

void get_prime(int x)
{
    for(int i = 2; i <= x / i; i++) 
    {
        if(x % i == 0) 
        {
            int c = 0;
            while(x % i == 0) x /= i, c++;
            printf("%d %d\n", i, c);
        }
    }
    
    if(x > 1) printf("%d %d\n", x, 1);
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
        
        get_prime(x);
    }
    
    return 0;
}
