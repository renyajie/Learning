// kruskal适用于稀疏图，时间复杂夫mlogm
int n, m; // n是点数，m是边数
int p[N]; // 并查集的父节点数组

struct edge {
	int a, b, w;

	bool operator< (const edge &W) const {
		return w < W.w;
	}
} e[M];

int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int kruskal() {
	sort(e, e + m);

	for(int i = 1; i <= n; i++) p[i] = i;

	int res = 0, cnt = 0;
	for(int i = 0; i < m; i++) {
		int a = e[i].a, b = e[i].b, w = e[i].w;
		
		a = find(a), b = find(b);
		if(a != b) { // 如果两个连通块不连通，则将这两个连通块合并
			p[a] = b;
			res += w;
			cnt++;
		}
	}

	if(cnt < n - 1) return INF;
	return res;
}
