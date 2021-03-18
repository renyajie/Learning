#include<iostream>
#include<cstring>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int g[N][N], d[N];
bool st[N];
int n, m;

int prim() {
    memset(d, 0x3f, sizeof d);
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        int t = -1;
        for(int j = 1; j <= n; j++) {
            if(!st[j] && (t == -1 || d[j] < d[t])) {
                t = j;
            }
        }
        if(i && d[t] == INF) return INF;
        if(i) res += d[t];
        st[t] = true;
        
        for(int j = 1; j <= n; j++) d[j] = min(d[j], g[t][j]);
    }
    
    return res;
}

int main() {
    memset(g, 0x3f, sizeof g);
    
    scanf("%d%d", &n, &m);
    while(m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    int ans = prim();
    
    if(ans == INF) puts("impossible");
    else printf("%d\n", ans);
    
    return 0;
}
