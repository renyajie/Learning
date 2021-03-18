#include<iostream>
#include<cstring>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

unordered_map<string, int> dis;
unordered_map<string, pair<char, string>> st; 
char g[2][4];

void get(string str)
{
    for(int i = 0; i < 4; i++) g[0][i] = str[i];
    for(int i = 3, j = 4; i >= 0; i--, j++) g[1][i] = str[j];
}

string set()
{
    string str;
    for(int i = 0; i < 4; i++) str += g[0][i];
    for(int i = 3, j = 4; i >= 0; i--, j++) str += g[1][i];
    return str;
}

string move1(string str)
{
    get(str);
    
    for(int j = 0; j < 4; j++)
    {
        swap(g[1][j], g[0][j]);
    }
    
    return set();
}

string move2(string str)
{
    get(str);
    
    char a = g[0][3], b = g[1][3];
    for(int j = 2; j >= 0; j--)
    {
        for(int i = 0; i < 2; i++)
        {
            g[i][j + 1] = g[i][j];
        }
    }
    
    g[0][0] = a, g[1][0] = b;
    
    return set();
}

string move3(string str)
{
    get(str);
    
    char v = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = v;
    
    return set();
}


int bfs(string start, string end)
{
    queue<string> q;
    q.push(start);
    dis[start] = 0;
    
    while(!q.empty())
    {
        string p = q.front(); q.pop();
        
        if(p == end) return dis[p];
    
        //cout << p << endl;
        
        string m[3];
        m[0] = move1(p);
        m[1] = move2(p);
        m[2] = move3(p);
        
        for(int i = 0; i < 3; i++)
        {
            if(dis.count(m[i]) != 0) continue;
            q.push(m[i]);
            dis[m[i]] = dis[p] + 1;
            st[m[i]] = {'A' + i, p};
            if(m[i] == end) return dis[end];
        }
    }
    
    return -1;
}

int main()
{
    string start, end;
    for(int i = 0; i < 8; i++) start += char(i + '1');
    
    for(int i = 0; i < 8; i++)
    {
        int x; cin >> x;
        end += char(x + '0');
    }
    
    int cnt = bfs(start, end);
    cout << cnt << endl;
    string res;
    while(end != start)
    {
        res += st[end].first;
        end = st[end].second;
    }
    
    reverse(res.begin(), res.end());
    if(cnt > 0) cout << res << endl;
    
    return 0;
}
