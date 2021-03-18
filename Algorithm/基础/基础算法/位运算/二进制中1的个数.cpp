// 输入n个数字，求每个数字中1的个数
#include<iostream>
using namespace std;

int n;

int main() {
	scanf("%d", &n);

	while(n--) {
		int x, t = 0;
		scanf("%d", &x);
		while(x) {
			x -= x & -x;
			t++;
		}
		printf("%d ", t);
	}
	
	return 0;
}
