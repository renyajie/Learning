#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;

const int N = 2e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
int d[N];
bool st[N];
int n, m;

void init() {
	memset(h, -1, sizeof h);
	idx = 0;
}

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, 1});

	while(q.size()) {
		auto p = q.top();
		q.pop();
		int id = p.second, distance = p.first;
		if(st[id]) continue;
		st[id] = true;
		for(int i = h[id]; i != -1; i = ne[i]) {
			int j = e[i];
			if(d[j] > distance + w[i]) {
				d[j] = distance + w[i];
				q.push({d[j], j});
			}
		}
	}

	if(d[n] == 0x3f3f3f3f) return -1;
	return d[n];
}

int main() {
	init();
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}

	printf("%d", dijkstra());
	return 0;
}
