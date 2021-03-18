#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        pq.push(x);
    }
    
    int res = 0;
    while(pq.size() > 1)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        res += a + b;
        pq.push(a + b);
    }
    
    printf("%d\n", res);
    
    return 0;
}
