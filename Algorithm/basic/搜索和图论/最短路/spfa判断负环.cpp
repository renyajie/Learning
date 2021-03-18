#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 2010, M = 10010;

int h[N], e[M], ne[M], w[M], idx;
int d[N], cnt[N];
bool st[N];
int n, m;

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        st[i] = true;
        q.push(i);
    }
    
    while(q.size()) {
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for(int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if(d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                cnt[j]  = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    
    return false;
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    if(spfa()) puts("Yes");
    else puts("No");
    
    return 0;
}
