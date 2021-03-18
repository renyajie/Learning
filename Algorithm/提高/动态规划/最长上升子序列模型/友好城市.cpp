#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5010;

typedef pair<int,int> PII;

PII city[N];
int dp[N];

int main()
{
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        city[i] = {a, b};
    }
    
    sort(city, city + n);
    
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(city[i].second > city[j].second) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
    
    return 0;
}
