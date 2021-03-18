// 给定一个数组，求每个大小为k的窗口的最小值和最大值
#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N], q[N], hh = 0, tt = -1;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	for(int i = 0; i < n; i++) {
		if(hh <= tt && q[hh] < i - k + 1) hh++;
		while(hh <= tt && a[q[tt]] >= a[i]) tt--;
		q[++tt] = i;
		if(i >= k - 1) printf("%d ", a[q[hh]]);
	}

	printf("\n")
	hh = 0, tt = -1;
	for(int i = 0; i < n; i++) {
		if(hh <= tt && q[hh] < i - k + 1) ++hh;
		while(hh <= tt && a[q[tt]] <= a[i]) tt--;
		q[++tt] = i;
		if(i >= k - 1) printf("%d ", a[q[hh]]);
	}
	return 0;
}
