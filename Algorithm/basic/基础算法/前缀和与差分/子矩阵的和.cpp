#include<iostream>
using namespace std;

const int N = 1010;

int n, m, q;
int b[N][N];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
		}
	}

	while(q--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1]);
	}
	return 0;
}
