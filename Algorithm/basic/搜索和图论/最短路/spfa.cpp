// spfa 一般复杂度m, 最坏复杂度(nm)，负向边和正向便都可以
// 如果存在负环路会死循环，一般得可用cnt来判断

int n; // 总点数
int h[N], e[N], ne[N], w[N], idx; // 邻接表
int dist[N]; // 存储每个点到1号点的距离
bool st[N]; // 存储每个点是否在队列中

// 求1号点到n号点的最短距离，如果1号点无法走到n号点返回-1
int spfa() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	queue<int> q;
	q.push(1);
	st[1] = true;

	while(q.size()) {
		auto t = q.front(); 
		q.pop();

		st[t] = false;

		for(int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if(!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}

	if(dist[n] > 0x3f3f3f3f / 2) return -1;
	return dist[n];
}
