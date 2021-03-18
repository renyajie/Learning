// 求出所有模式串在主串中的位置
#include<iostream>
using namespace std;

const int N = 1e6 + 10;

int ne[N];
char s[N], p[N];

int main() {
	int n, m;
	scanf("%d%s%d%s", &n, p + 1, &m, s + 1);

	for(int i = 2, j = 0; i <= n; i++) {
		while(j && p[i] != p[j + 1]) j = ne[j];
		if(p[i] == p[j + 1]) j++;
		ne[i] = j;
	}

	for(int i = 1, j = 0; i <= m; i++) {
		while(j && p[i] != p[j + 1]) j = ne[j];
		if(p[i] == p[j + 1]) j++;
		if(j == n) {
			j = ne[j];
			printf("%d ", i - n);
		}
	}
	return 0;
}
