// 朴素Dijkstra算法，适用于正边，稠密图
// 一般稠密图，边的数量m=n^2
int g[N][N]; // 存储每条边
int dist[N]; // 存储1号点到每个点的最短距离
bool st[N]; // 存储每个点的最短路径是否已经确定

// 求1号点到n号点的最短路，如果不存在则返回-1
int dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	for(int i = 0; i < n - 1; i++) {
		int t = -1; // 在还没确定最短路的殿中寻找距离最小的
		for(int j = 1; j <= n; j++) {
			if(!st[j] && (t == 1 || dist[t] > dist[j])) {
				t = j;
			}
		}

		// 用t更新其他点的距离
		for(int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		}

		st[t] = true;
	}

	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}
