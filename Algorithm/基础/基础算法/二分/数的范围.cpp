// 一个升序数组，有q个查询，每次查询会输入一个数字，求这个
// 数字在数组中的最小下标和最大下标，不存在输出-1 -1
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	for(int i = 0; i < q; i++) {
		int k, p1, p2;
		scanf("%d", &k);

		int l = 0, r = n - 1;
		while(l < r) {
			int mid = l + r >> 1;
			if(a[mid] >= k) r = mid;
			else l = mid + 1;
		}
		
		if(a[l] != k) {
			printf("-1 -1\n");
			continue;
		}

		p1 = l;
		l = 0, r = n - 1;
		while(l < r) {
			int mid = l + r + 1 >> 1;
			if(a[mid] <= k) l = mid;
			else r = mid - 1;
		}
		
		p2 = l;
		printf("%d %d\n", p1, p2);
	}
	return 0;
}
