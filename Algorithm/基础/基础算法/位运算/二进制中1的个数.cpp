// ����n�����֣���ÿ��������1�ĸ���
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
