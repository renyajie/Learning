#include<iostream>
using namespace std;

const int N = 10;
int path[N];
bool st[N];
int n;

void dfs(int k) {
	if(k == n) {
		for(int i = 0; i < n; i++) printf("%d ");
		printf("\n")
		return;
	}

	for(int i = 1; i <= n; i++) {
		if(st[i]) continue;
		st[i] = true;
		path[k] = i;
		dfs(k + 1);
		st[i] = false;
	}
}

int main() {
	scanf("%d", &n);

	dfs(0);

	return 0;
}
