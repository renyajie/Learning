// 一个数组，输出每个数字左边第一个比它小的数字，不存在输出-1
#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int st[N], tt = 0, a[N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	for(int i = 0; i < n; i++) {
		while(tt && st[tt] >= a[i]) tt--;
		printf("%d ", !tt ? -1 : st[tt]);
		st[++tt] = a[i];
	}
	return 0;
}
