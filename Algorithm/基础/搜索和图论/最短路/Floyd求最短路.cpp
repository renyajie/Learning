#include<iostream>
#include<cstring>
using namespace std;

const int N = 210;
int d[N][N];
int n, m, k;

void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) d[i][j] = 0;
            else d[i][j] = 0x3f3f3f3f;
        }
    }
    
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }
    
    floyd();
    
    for(int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(d[a][b] > 0x3f3f3f3f / 2) puts("impossible");
        else printf("%d\n", d[a][b]);
    }
    
    return 0;
}
