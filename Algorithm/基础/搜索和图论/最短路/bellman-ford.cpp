// bellman-ford，适用于负向边，效率为nm，不如spfa，但是有边数限制的负向边最短路只能用这个算法

struct Edge {
	int a, b, w;
} e[M]; // 保存边

int dist[N], back[N]; // 备份数组防止串联
int n, m, k; // k代表最短路最多包含k条边

int bellman_ford() {
	memset(dist, 0x3f3f3f3f, sizeof dist);
	dist[1] = 0;
	for(int i = 0; i < k; i++) { // k次循环
		memcpy(back, dist, sizeof dist);
		for(int j = 0; j < m; j++) {
			int a = e[j].a, b = e[j].b, w = e[j].w;
			dist[b] = min(dist[b], back[a] + w); // 备份数组更新，防串联
		}
	}

	if(dist[n] > 0x3f3f3f3f / 2) return -1;
	return dist[n];
}
