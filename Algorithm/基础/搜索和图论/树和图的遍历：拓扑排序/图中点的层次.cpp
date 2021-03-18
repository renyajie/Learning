// 求出树中1号点到n号点的最短距离
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int d[N], q[N];
int n, m;

void init() {
	memset(h, -1, sizeof h);
	idx = 0;
}

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs() {
	memset(d, -1, sizeof d);
	d[1] = 0;
	int hh = 0, tt = -1;
	q[++tt] = 1;

	while(hh <= tt) {
		int p = q[hh++];
		for(int i = h[p]; i != -1; i = ne[i]) {
			int j = e[i];
			if(d[j] == -1) {
				d[j] = d[p] + 1;
				q[++tt] = j;
			}
		}
	}
	return d[n];
}

int main() {
	init();

	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}

	printf("%d", bfs());
	return 0;
}
