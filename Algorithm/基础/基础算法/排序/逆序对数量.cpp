// 求一个数组中的逆序对数量
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], tmp[N];

long long merge_sort(int q[], int l, int r) {
	if(l >= r) return 0;

	long long ans = 0;
	int mid = l + r >> 1;
	ans += merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

	int k = 0, i = l, j = mid + 1;
	while(i <= mid && j <= r) {
		if(q[i] <= q[j]) tmp[k++] = q[i++];
		else tmp[k++] = q[j++], ans += mid - i + 1;
	}
	while(i <= mid) tmp[k++] = q[i++];
	while(j <= r) tmp[k++] = q[j++];

	for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &n);

	printf("%lld", merge_sort(a, 0, n - 1));
	return 0;
}
