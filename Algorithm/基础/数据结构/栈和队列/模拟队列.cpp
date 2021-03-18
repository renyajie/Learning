#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;

int q[N], hh = 0, tt = -1;

int main() {
	int m;
	scanf("%d", &m);

	char op[10];
	while(m--) {
		scanf("%s", op);
		if(!strcmp(op, "push")) {
			int x;
			scanf("%d", &x);
			q[++tt] = x;
		}
		else if(!strcmp(op, "pop")) {
			++hh;
		}
		else if(!strcmp(op, "empty")) {
			printf(hh > tt ? "YES\n" : "NO\n");
		}
		else {
			printf("%d\n", q[hh]);
		}
	}
	return 0;
}
