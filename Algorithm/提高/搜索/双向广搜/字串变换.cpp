#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

const int N = 10;

string a[N], b[N];
int n;

int extend(queue<string> &q, unordered_map<string, int> &da, unordered_map<string, int> &db, string oa[], string ob[])
{
    string p = q.front(); q.pop();
    
    for(int i = 0; i < p.size(); i++)
    {
        for(int j = 0; j < n; j++)
        {
            int m = oa[j].size();
            if(p.substr(i, m) == oa[j])
            {
                string np = p.substr(0, i) + ob[j] + p.substr(i + m);
                if(da.count(np)) continue;
                if(db.count(np)) return db[np] + da[p] + 1;
                da[np] = da[p] + 1;
                q.push(np);
            }
        }
    }
    
    return 11;
}

int bfs(string start, string end)
{
    queue<string> qa, qb;
    unordered_map<string, int> da, db;
    qa.push(start);
    da[start] = 0;
    qb.push(end);
    db[end] = 0;
    
    while(qa.size() && qb.size())
    {
        int t;
        if(qa.size() <= qb.size()) t = extend(qa, da, db, a, b);
        else t = extend(qb, db, da, b, a);
        
        if(t <= 10) return t;
    }
    
    return 11;
}

int main()
{
    string start, end;
    cin >> start >> end;
    
    n = 0;
    while(cin >> a[n] >> b[n]) n++;
    
    int t = bfs(start, end);
    
    if(t > 10) puts("NO ANSWER!");
    else printf("%d\n", t);
    
    return 0;
}
