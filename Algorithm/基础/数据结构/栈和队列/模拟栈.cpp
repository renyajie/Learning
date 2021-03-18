#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10£»

int st[N], tt = 0;

int main() {
	int m;
	scanf("%d", &m);

	char op[10];
	while(m--) {
		scanf("%s", op);
		if(!strcmp(op, "push")) {
			int x;
			scanf("%d", &x);
			st[++tt] = x;
		}
		else if(!strcmp(op, "pop")) {
			tt--;
		}
		else if(!strcmp(op, "empty")) {
			printf(tt == 0 ? "YES\n" : "NO\n");
		}
		else {
			printf("%d\n", st[tt]);
		}
	}
	return 0;
}
