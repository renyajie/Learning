#include<iostream>
using namespace std;

const int N = 1e5 + 10;

int p[N];

int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) p[i] = i;

	for(int i = 0; i < m; i++) {
		char op[10];
		int a, b;
		scanf("%s%d%d", op, &a, &b);
		if(op[0] == 'Q') printf(find(a) == find(b) ? "Yes\n" : "No\n");
		else p[find(a)] = find(b);
	}
	return 0;
}
