#include<iostream>
#include<vector>
using namespace std;

typedef pair<int,int> PII;

const int N = 32010, M = 70;

int dp[N];
PII master[M];
vector<PII> servent[M];


int main()
{
    int m, n; scanf("%d%d", &m, &n);
    
    for(int i = 1; i <= n; i++)
    {
        int v, p, q; scanf("%d%d%d", &v, &p, &q);
        if(q == 0) master[i] = {v, p * v};
        else servent[q].push_back({v, p * v});
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= 0; j--)
        {
            for(int k = 0; k < 1 << servent[i].size(); k++)
            {
                int v = master[i].first, w = master[i].second;
                
                for(int q = 0; q < servent[i].size(); q++)
                {
                    if(k >> q & 1)
                    {
                        v += servent[i][q].first;
                        w += servent[i][q].second;
                    }
                }
                
                if(j >= v) dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }
    
    printf("%d\n", dp[m]);
    
    return 0;
}
