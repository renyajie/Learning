#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], ne[N], w[N], idx;
int d[N];
bool st[N];
int n, m;

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    st[1] = true;
    queue<int> q;
    q.push(1);
    
    while(q.size()) {
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for(int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if(d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                if(!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    if(d[n] > 0x3f3f3f3f / 2) return -1;
    return d[n];
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    
    int ans = spfa();
    
    if(ans == -1) puts("impossible");
    else printf("%d", ans);
    
    return 0;
}
