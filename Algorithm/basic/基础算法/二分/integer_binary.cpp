bool check(int x) { /* ... */ } //检查x是否满足某种性质

// 向左边收缩，移动R：考虑右半边满足的条件
int bsearch_1(int l, int r) {
	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	return l'
}

// 向右边收缩，移动L：考虑左半边满足的条件
int bsearch_2(int l, int r) {
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}
