// 判断数组A是不是数组B的子序列
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N], b[N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < m; i++) scanf("%d", &b[i]);

	bool find = true;
	for(int i = 0, j = 0; i < n; i++, j++) {
		while(j < m && a[i] != b[j]) j++;
		if(j == m) { find = false; break; }
	}

	printf(find ? "Yes" : "No");
	return 0;
}
