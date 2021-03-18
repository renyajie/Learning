// 求走出迷宫的最短路
#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;
typedef pair<int,int> PII;
int g[N][N], d[N][N];

PII q[N * N];
int n, m;

int bfs() {
	int hh = 0, tt = -1;
	memset(d, -1, sizeof d);
	q[++tt] = {0, 0};
	d[0][0] = 0;
	
	int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	while(hh <= tt) {
		PII p = q[hh++];
		int x = p.first, y = p.second;
		for(int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !g[nx][ny] && d[nx][ny] == -1) {
				d[nx][ny] = d[x][y] + 1;
				q[++tt] = {nx, ny};
			}
		}
	}
	return d[n - 1][m - 1];
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &g[i][j]);
		}
	}

	printf("%d", bfs());
	return 0;
}
