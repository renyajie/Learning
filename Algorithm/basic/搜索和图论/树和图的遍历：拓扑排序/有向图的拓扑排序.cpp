#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int q[N], d[N];
int n, m;

void init() {
	memset(h, -1, sizeof h);
	idx = 0;

	memset(d, 0, sizeof(d));
}

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort() {
	int hh = 0, tt = -1;
	for(int i = 1; i <= n; i++) {
		if(d[i] == 0) q[++tt] = i;
	}

	while(hh <= tt) {
		int p = q[hh++];
		for(int i = h[p]; i != -1; i = ne[i]) {
			int j = e[i];
			if(--d[j] == 0) {
				q[++tt] = j;
			}
		}
	}
	return tt == n - 1;
}

int main() {
	init();
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		d[b]++;
	}

	if(topsort()) {
		for(int i = 0; i < n; i++) printf("%d ", q[i]);
		printf("\n");
	}
	else printf("-1");
	return 0;
}
