// floyd算法 n^3，多源最短路，边权是负数也没事，判断0x3f3f3f3f / 2即可

// 初始化
for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= n; j++) {
		if(i == j) d[i][j] = 0;
		else d[i][j] = INF;
	}
}

// 算法结束后，d[a][b]表示a到b的最短距离
void floyd() {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
