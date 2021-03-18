#include<iostream>
#include<cstring>
using namespace std;

const int N = 510, M = 10010;

struct edge {
    int a, b, c;
}e[M];

int d[N], back[N];
int n, m, k;

int bellman_ford() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    
    for(int i = 0; i < k; i++) {
        memcpy(back, d, sizeof d);
        for(int j = 0; j < m; j++) {
            d[e[j].b] = min(d[e[j].b], back[e[j].a] + e[j].c);
        }
    }
    
    if(d[n] > 0x3f3f3f3f / 2) return -1;
    return d[n];
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[i] = {a, b, c};
    }
    
    int ans = bellman_ford();
    
    if(ans == -1) puts("impossible");
    else printf("%d", ans);
    return 0;
}
