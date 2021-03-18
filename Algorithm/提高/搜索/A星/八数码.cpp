#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

typedef pair<int, string> PIS;

int f(string s)
{
    int ans = 0;
    for(int i = 0; i < 9; i++)
    {
        if(s[i] == 'x') continue;
        int t = s[i] - '1';
        ans += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
    }
    return ans;
}

string bfs(string start, string end)
{
    priority_queue<PIS, vector<PIS>, greater<PIS>> pq;
    unordered_map<string, pair<char, string>> prev;
    unordered_map<string, int> dis;
    
    pq.push({f(start), start});
    dis[start] = 0;
    
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    char op[5] = "udrl";
    
    // cout << "a" << endl;
    
    while(pq.size())
    {
        auto p = pq.top(); pq.pop();
        string s = p.second;
        if(s == end) break;
        
        int px = 0, py = 0;
        for(int i = 0; i < 9; i++)
        {
            if(s[i] == 'x')
            {
                px = i / 3, py = i % 3;
                break;
            }
        }
        
        string source = s;
        for(int i = 0; i < 4; i++)
        {
            int nx = px + dir[i][0], ny = py + dir[i][1];
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            
            swap(source[nx * 3 + ny], source[px * 3 + py]);
            
            if(!dis.count(source) || dis[source] > dis[s] + 1) // 当前的点没有遍历，或当前点的距离可能会更小
            {
                dis[source] = dis[s] + 1;
                pq.push({dis[source] + f(source), source});
                prev[source] = {op[i], s};
            
            }
            swap(source[nx * 3 + ny], source[px * 3 + py]);
            
        }
    }
    
    string res;
    while(end != start)
    {
        res += prev[end].first;
        end = prev[end].second;
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}

int main()
{
    string end = "12345678x";
    string start, seq;
    char x;
    while(cin >> x)
    {
        start += x;
        if(x != 'x') seq += x;
    }
    
    int cnt = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = i + 1; j < 9; j++)
        {
            if(seq[i] > seq[j]) cnt++;
        }
    }
    
    if(cnt & 1) puts("unsolvable");
    else 
    {
        cout << bfs(start, end) << endl;
    }
    
    return 0;
}
