// ����һ����Χ��[-1000, 1000]�����֣������η���
#include<iostream>
using namespace std;

int main() {
	double x;
	scanf("%lf", &x);

	double l = -1000, r = 1000;
	for(int i = 0; i < 100; i++) {
		double mid = (l + r) / 2;
		if(mid * mid * mid <= x) l = mid;
		else r = mid;
	}

	printf("%lf", l);
	return 0;
}
