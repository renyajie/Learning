#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;
int e[N], l[N], r[N], idx;

void init() {
	r[0] = 1, l[1] = 0, idx = 2;
}

void remove(int k) {
	l[r[k]] = l[k], r[l[k]] = r[k];
}

void insert(int k, int x) {
	e[idx] = x;
	r[idx] = r[k], l[idx] = k;
	l[r[k]] = idx, r[k] = idx, idx++;
}

int main() {
	int m;
	scanf("%d", &m);

	init();
	while(m--) {
		char op[10];
		scanf("%s", op);
		int k, x;
		if(!strcmp(op, "L")) {
			scanf("%d", &x);
			insert(0, x);
		}
		else if(!strcmp(op, "R")) {
			scanf("%d", &x);
			insert(l[1], x);
		}
		else if(!strcmp(op, "D")) {
			scanf("%d", &k);
			remove(k + 1);
		}
		else if(!strcmp(op, "IL")) {
			scanf("%d%d", &k, &x);
			insert(l[k + 1], x);
		}
		else {
			scanf("%d%d", &k, &x);
			insert(k + 1, x);
		}
	}

	for(int i = r[0]; i != 1; i = r[i]) printf("%d ", e[i]);
	return 0;
}
