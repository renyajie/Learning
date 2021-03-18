// 朴素并查集
// *********************
int p[N]; // 存储每个节点的祖宗个数

// 返回x的祖宗节点
int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

// 初始化，假定节点编号是1~n
for(int i = 1; i <= n; i++) p[i] = i;

// 合并a和b所在的两个集合
p[find(a)] = find(b);



// 维护集合个数的并查集
// *********************
int p[N], size[N]; // size表示每个点所在集合的元素个数，只有根节点有意义

// 返回x的祖宗节点
int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

// 初始化，假定节点编号是1~n
for(int i = 1; i <= n; i++) {
	p[i] = i, size[i] = 1;
}

// 合并a和b所在的两个集合
size[find(b)] += size[find(a)];
p[find(a)] = find(b);


// 维护到祖先节点距离的并查集
// **********************

int p[N], d[N]; //d[x]存储x到p[x]的距离

// 返回x的祖先节点
int find(int x) {
	if(p[x] != x) {
		int u = find(p[x]);
		d[x] += d[p[x]];   // 在进行路径压缩之前先累加距离
		p[x] = u;
	}
	return p[x];
}

// 初始化，假定节点编号是1~n
for(int i = 1; i <= n; i++) {
	p[i] = i, d[i] = 0;
}

// 合并a和b所在的两个集合
p[find(a)] = find(b);
d[find(a)] = distance; // 根据具体的问题，初始化


