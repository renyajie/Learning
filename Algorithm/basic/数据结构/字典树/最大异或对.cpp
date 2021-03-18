// 给你一个数组，选出任意两个数字，求最大的异或结果

#include<iostream>
using namespace std;

const int N = 1e5 + 10, M = 30 * N;

int son[M][2], idx;
int a[N];

void insert(int n) {
	int p = 0;
	for(int i = 30 ; i >= 0; i--) {
		int u = n >> i & 1;
		if(!son[p][!u]) p = son[p][u], res |= u << i;
		else p = son[p][!u], res |= !u << i;
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	for(int i = 0; i < n; i++) insert(a[i]);

	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, query(a[i]) ^ a[i]);
	printf("%d", ans);
	return 0;
}
