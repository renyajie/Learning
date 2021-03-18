// 注意：前缀和的角标都从1开始，避免边界判断

// 一维前缀和 
// S[i] = a[1] + a[2] + ... + a[i]
// a[l] + ... + a[r] = S[r] - S[l - 1]

for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];


// 二维前缀和
// S[i][j] = 第i行j列格子坐上部分所有元素的和
// 以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和：
// S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1-1][y1-1]

for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= m; j++) {
		scanf("%d", &s[i][j]);
	}
}

for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= m; j++) {
		s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
	}
}

