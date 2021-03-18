// 核心思想：将字符串看成P进制数字，P的经验值是131或13331，冲突低
// 小技巧：取模用2^64,直接用unsigned long long存储，溢出的结果就是取模的结果

typedef unsigned long long ULL;
ULL h[N], p[N]; // h[N] 存前k个字母的哈希值，p[k]存储p^k mod 2^64
int P = 131;

// 初始化
p[0] = 1;
for(int i = 1; i <= n; i++) {
	h[i] = h[i - 1] * P + str[i];
	p[i] = p[i - 1] * P;
}

// 计算字串str[l ~ r]的哈希值
ULL get(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
