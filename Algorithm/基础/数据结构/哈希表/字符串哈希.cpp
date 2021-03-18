// 判断一个字符串两个区间的字符子串是否相同

#include<iostream>
using namespace std;

const int N = 1e5 + 10;
typedef unsigned long long ULL;

ULL h[N], p[N];
char str[N];
int P = 131;

ULL get(int l, int r) {
	return h[r] - h[l - 1] * (r - l + 1);
}

int main() {
	int n, m;
	scanf("%d%d%s", &n, &m, str + 1);

	p[0] = 1;
	for(int i = 1; i <= n; i++) {
		h[i] = h[i - 1] * P + str[i];
		p[i] = p[i - 1] * P;
	}

	while(m--) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		printf(get(l1, r1) == get(l2, r2) ? "Yes\n" : "No\n");
	}
	return 0;
}
