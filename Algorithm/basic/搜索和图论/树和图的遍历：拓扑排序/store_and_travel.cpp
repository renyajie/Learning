// 树和图的存储方式相同
// 邻接矩阵：g[a][b] 存储a->b

// 邻接表：
// 对于每一个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头节点
int h[N], e[N], ne[N], idx;

// 添加一条边a->b
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 初始化
idx = 0;
memset(h, -1, sizeof h);

// **********************************
// 树和图的遍历
// 时间复杂度O(n+m)，n表示点数，m表示边数
// 1. 深度优先遍历
int dfs(int u) {
	st[u] = true; // st[u]表示点i已经被遍历过
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[j];
		if(!st[j]) dfs(j);
	}
}

// 2. 宽度优先遍历
queue<int> q;
st[1] = true; // 表示1号点已经被遍历过
q.push(1);

while(q.size()) {
	int t = q.front();
	q.pop();

	for(int i = h[t]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			st[j] = true;
			q.push(j);
		}
	}
}
