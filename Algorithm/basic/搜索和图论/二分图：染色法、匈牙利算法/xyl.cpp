// 匈牙利算法O(nm)，使用计算二分图的最大匹配
int n1, n2; // n1表示第一个集合中的点数，n2表示第二个集合中的点数
int h[N], e[N], ne[N], idx;
int match[N]; // 第二个集合中每个点当前匹配的第一个点是哪个
bool st[N]; // 第二个集合中的每个点是否已经被遍历过

bool find(int x) {
	for(int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			st[j] = true;
			if(match[j] == 0 || find(match[j])) {
				match[j] = x;
				return true;
			}
		}
	}

	return false;
}

// 求最大匹配数， 依次枚举每个点能否匹配第二个集合中的点
int res = 0;
for(int i = 1; i <= n1; i++) {
	memset(st, false, sizeof st);
	if(find(i)) res++;
}
