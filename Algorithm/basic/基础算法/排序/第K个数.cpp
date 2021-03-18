// 求一个数组中第K大的数字

#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int quick_sort(int q[], int l, int r, int k) {
	if(l >= r) return q[l];

	int i = l - 1, j = r + 1, x = q[l + r >> 1];
	while(i < j) {
		do i++; while(q[i] < x);
		do j--; while(q[j] > x);
		if(i < j) swap(q[i], q[j]);
	}
	
	if(j >= k) return quick_sort(q, l, j, k);
	return quick_sort(q, j + 1, r, k);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	printf("%d", quick_sort(a, 0, n - 1, k - 1));
	return 0;
}
