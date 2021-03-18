// 染色法：O(n+m)
int n, m; // n表示点数
int h[N], e[N], ne[N], idx; // 邻接图存储
int color[N]; // 表示每个点的颜色，-1表示未染色

// 参数：u表示当前节点，c表示当前点的颜色
bool dfs(int u, int c) {
	color[u] = c;
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(color[j] == -1) {
			if(!dfs(j, !c)) return false;
		}
		else if(color[j] == c) return false;
	}

	return true;
}

bool check() {
	memset(color, -1, sizeof color);
	bool flag = true;
	for(int i = 1; i <= n; i++) {
		if(color[i] == -1) {
			if(!dfs(i, 0)) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}
