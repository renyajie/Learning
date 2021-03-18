// e[]表示节点的值，l[]表示左指针, r[]表示右指针, idx表示当前用到哪个点
int e[N], l[N], r[N], idx;

// 初始化
void init() {
	// 0是左端点，1是右端点
	r[0] = 1, l[1] = 0;
	idx = 2;
}

// 在节点a的右边插入一个点
void insert(int a, int x) {
	e[idx] = x;
	l[idx] = a, r[idx] = r[a];
	l[r[a]] = idx, r[a] = idx;
	idx++;
}

// 删除节点a
void remove(int a) {
	l[r[a]] = l[a];
	r[l[a]] = r[a];
}


