#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 1e5 + 10;

struct Range
{
    int l, r;
    bool operator< (const Range& W) const
    {
        return l < W.l;
    }
} range[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }
    
    sort(range, range + n);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(range[0].r);
    for(int i = 1; i < n; i++)
    {
        if(pq.top() < range[i].l)
        {
            pq.pop();
            pq.push(range[i].r);
        }
        else 
        {
            pq.push(range[i].r);
        }
    }
    
    printf("%d\n", pq.size());
    
    return 0;
}
