#include<iostream>
#include<cstring>
using namespace std;

const int N = 2e5 + 10, null = 0x3f3f3f3f;
int h[N];

int find(int x) {
	int t = (x % N + N) % N;
	while(h[t] != null && h[t] != x) {
		t++;
		if(t == N) t = 0;
	}
	return t;
}

int main() {
	int n;
	scanf("%d", &n);

	memset(h, 0x3f, sizeof h);
	char op[10];
	int x;
	while(n--) {
		scanf("%s%d", op, &x);
		if(op[0] == 'I') h[find(x)] = x;
		else printf(h[find(x)] != null ? "Yes\n" : "No\n");
	}
	return 0;
}
