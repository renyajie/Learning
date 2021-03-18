// 用堆给N个数字排序后，输出最小的M个数字
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int h[N], sz;

void down(int x) {
	int t = x;
	if(x * 2 <= sz && h[x * 2] < h[t]) t = x * 2;
	if(x * 2 + 1 <= sz && h[x * 2 + 1] < h[t]) t = x * 2 + 1;
	if(t != x) {
		swap(h[x], h[t]);
		down(t);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &h[i]);

	sz = n;
	for(int i = n / 2; i; i--) down(i);

	while(m--) {
		printf("%d ", h[1]);
		h[1] = h[sz], sz--, down(1);
	}
	return 0;
}
