#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int h[N], e[M], ne[M], idx;
int color[N];
int n, m;

void init() {
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c) {
    color[u] = c;
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if(color[j] == -1) {
            if(!dfs(j, !c)) return false;
        }
        else if(color[j] == c) return false;
    }
    
    return true;
}

int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    bool flag = true;
    memset(color, -1, sizeof color);
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            if(!dfs(i, 0)) {
                flag = false;
                break;
            }
        }
    }
    
    if(flag) puts("Yes");
    else puts("No");
    
    return 0;
}
