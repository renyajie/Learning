#include<iostream>
using namespace std;

const int N = 2 * N;
bool col[N], dia[N], adia[N];
int n;
char g[N][N];

void dfs(int k) {
	if(k == n) {
		for(int i = 0; i < n; i++) printf("%s\n", g[i]);
		printf("\n");
		return;
	}

	for(int i = 0; i < n; i++) {
		if(col[i] || dia[k + i] || adia[n + k - i]) continue;
		col[i] = dia[k + i] = adia[n + k - i] = true;
		g[k][i] = 'Q';
		dfs(k + 1);
		g[k][i] = '.';
		col[i] = dia[k + i] = adia[n + k - i] = false;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			g[i][j] = '.';
		}
	}

	dfs(0);

	return 0;
}
