// 求删除一个树节点后，使得各个连通块点数的最大值最小化
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;
const int M = 2 * N;
int h[N], e[M], ne[M], idx;
int n, ans = N;
bool st[N];

void init() {
	memset(h, -1, sizeof h);
	idx = 0;
}

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int k) {
	st[k] = true;
	int res = 0, sum = 1;
	for(int i = h[k]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			int t = dfs(j);
			res = max(res, t);
			sum += t;
		}
	}
	res = max(res, n - sum);
	ans = min(ans, res);
	return sum;
}

int main() {
	init();

	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	
	dfs(1);

	printf("%d", ans);
	return 0;
}
