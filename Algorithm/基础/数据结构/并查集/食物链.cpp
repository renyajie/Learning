// 食物链，A吃B，B吃C，C吃A，求假话有多少句
#include<iostream>
using namespace std;

const int N = 5e4 + 10;
int p[N], d[N];

int find(int x) {
	if(p[x] != x) {
		int u = find(p[x]);
		d[x] += d[p[x]];
		p[x] = u;
	}
	return p[x];
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) p[i] = i;

	int ans = 0;
	while(m--) {
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if(a > n || b > b) ans++;
		else {
			int pa = find(a), pb = find(b);
			if(t == 1) {
				if(pa == pb) {
					if((d[a] - d[b]) % 3) ans++;
				}
				else {
					p[pa] = pb;
					d[pa] = d[b] - d[a];
				}
			}
			else {
				if(pa == pb) {
					if((d[a] - d[b] - 1) % 3) ans++;
				}
				else {
					p[pa] = pb;
					d[pa] = d[b] + 1 - d[a];
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
