// prim算法时间复杂度n^2, 适用于稠密图
int n; // n表示点数
int g[N][N]; // 邻接矩阵，存储所有边
int dist[N]; // 存储其他点到当前最小生成树的距离
bool st[N]; // 存储每个点是否在生成树中

// 如果图不连通，返回INF，否则返回最小生成树的戍边权重之和
int prim() {
	memset(dist, 0x3f, sizeof dist);

	int res = 0;
	for(int i = 0; i < n; i++) {
		int t = -1;
		for(int j = 1; j <= n; j++) {
			if(!st[j] && (t == -1 || dist[t] > dist[j])) {
				t = j;
			}
		}
			
		st[t] = true;
		if(i && dist[t] == INF) return INF;
		if(i) res += dist[t];
			
		for(int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], g[t][j]);
		}
	}

	return res;
}
