// 差分：适用于对区间修改的情况，对[l, r]区间内的所有数字加上c，最后做一次查询(多次查询用线段树)
// 差分是前缀和的逆运算，差分数组求前缀和得到原数组
// b[1] = a[1], b[2] = a[2] - a[1], b[3] = a[3] - a[2]...


// 一维差分
// 给区间[l, r]中的每个数字加上c：b[l] += c, b[r + 1] -= c
void insert(int l, int r, int c) {
	b[l] += c;
	b[r + 1] -= c;
}

for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
for(int i = 1; i <= n; i++) insert(i, i, a[i]); // 构造差分
while(m--) {
	int l, r, c;
	scanf("%d%d%d", &l, &r, &c);
	insert(l, r, c); // 差分操作
}
for(int i = 1; i <= n; i++) b[i] += b[i - 1]; // 恢复多次区间操作后的原数组


// 二维差分
// 给(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的所有元素加上c：
// S[x1][y1] += c; S[x2 + 1][y1] -= c; S[x1][y2 + 1] -= c; s[x2 + 1][y2 + 1] += c;

void insert(int x1, int y1, int x2, int y2, int c) {
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= m; j++) {
		scanf("%d", &a[i][j]);
	}
}

for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= m; j++) {
		insert(i, j, i, j, a[i][j]); // 构造二维差分
	}
}

while(q--) {
	int x1, y1, x2, y2, c;
	scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
	insert(x1, y1, x2, y2, c); // 差分操作
}

for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= m; j++) {
		b[i][j] += b[i-1][j] + b[i][j - 1] - b[i-1][j-1]; // 恢复多次区间操作后的原数组
	}
}
