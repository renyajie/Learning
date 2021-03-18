#include<iostream>
using namespace std;

const int N = 20;

int g[N][N];
string words[N];
int used[N];
int n;
int ans;

void dfs(int i, int cnt)
{
    ans = max(ans, cnt);
    used[i]++;
    
    for(int j = 0; j < n; j++)
    {
        if(g[i][j] && used[j] < 2)
        {
            dfs(j, cnt + words[j].size() - g[i][j]);
        }
    }
    used[i]--;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) cin >> words[i];
    char head; cin >> head;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            string a = words[i], b = words[j];
            for(int k = 1; k < min((int)a.size(), (int)b.size()); k++)
            {
                if(a.substr((int)a.size() - k) == b.substr(0, k))
                {
                    g[i][j] = k;
                    break;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        if(words[i][0] == head)
        {
            dfs(i, (int)words[i].size());
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
