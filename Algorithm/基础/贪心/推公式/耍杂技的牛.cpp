#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e5 + 10;

typedef long long ll;

typedef pair<int,int> PII;

PII cow[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) 
    {
        int w, s;
        scanf("%d%d", &w, &s);
        cow[i] = {w + s, s};
    }
    
    sort(cow, cow + n);
    
    ll res = -1e9, sum = 0;
    for(int i = 0; i < n; i++)
    {
        int s = cow[i].second, w = cow[i].first - s;
        res = max(res, sum - s);
        sum += w;
    }
    
    printf("%lld\n", res);
    
    return 0;
}
