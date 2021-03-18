// 堆优化的Dijkstra，适用于正向边，稀疏图
typedef pair<int,int> PII;

int n; // 点的数量
int h[N], e[N], ne[N], w[N], idx; // 邻接表存储所有边
int dist[N]; // 存储所有点到1号点的距离
bool st[N]; // 存储每个点的最短距离是否确定

int dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});

	while(heap.size()) {
		auto t = heap.top();
		heap.pop();

		int id = t.second, distance = t.first;
		if(st[id]) continue;
		st[id] = true;

		for(int i = h[id]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] > distance + w[i]) {
				dist[j] = distance + w[i];
				heap.push({dist[j], j});
			}
		}
	}

	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}
