// 两个升序数组和一个目标值x，求A[i]+B[i]=x的所有(i, j)
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, x;
int a[N], b[N];

int main() {
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < m; i++) scanf("%d", &b[i]);

	for(int i = 0, j = m - 1; i < n && j >= 0; i++) {
		while(j >= 0 && a[i] + b[j] > x) j--;
		if(j >= 0 && a[i] + b[j] == x) printf("%d %d\n", i, j);
	}
	return 0;
}
