#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int head, e[N], ne[N], idx;

void init() {
	head = -1, idx = 0;
}

void add_to_head(int x) {
	e[idx] = x, ne[idx] = head, head = idx++;
}

void insert(int k, int x) {
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void remove(int x) {
	ne[x] = ne[ne[x]];
}

int main() {
	int m;
	scanf("%d\n", &m); // 加上\n是为了让后面的字符能正确输入

	init();
	while(m--) {
		char op;
		int a, b;
		scanf("%c", &op);
		if(op == 'H') {
			scanf("%d\n", &a);
			add_to_head(a);
		}
		else if(op == 'I') {
			scanf("%d%d\n", &a, &b);
			insert(a - 1, b);
		}
		else {
			scanf("%d\n", &a);
			if(a == 0) head = ne[head];
			else remove(a - 1);
		}
	}

	for(int i = head; i = -1; i = ne[i]) printf("%d ", e[i]);
	return 0;
}
