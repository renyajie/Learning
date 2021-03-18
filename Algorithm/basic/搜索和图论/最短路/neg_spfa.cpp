// spfa判断负环
int n; // 总点数
int h[N], e[N], ne[N], w[N], idx; // 邻接表存储所有的边
int dist[N], cnt[N]; // dist[x]存储1号点到x的最短距离， cnt[x]表示到x的最短路的边数
bool st[N]; // 每个点是否在队列中

// 如果存在负环，返回true，否则返回false
bool spfa() {
	
	// 不需要初始化dist数组
	// 原来：如果某条最短路上n个点(除了自己)，那么加上自己n+1个，故比有2个点相同==》负环

	queue<int> q;
	for(int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = true;
	}

	while(q.size()) {
		auto t = q.front();
		q.pop();

		st[t] = false;
		for(int i = h[t]; i != -1' i = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if(cnt[j] >= n) return true; // 如果1号点到x的最短路至少包含n+1个，则有负环
				if(!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}

		return false;
	}
}
