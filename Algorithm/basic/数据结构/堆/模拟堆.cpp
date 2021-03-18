// 1. 插入一个数字
// 2. 输出最小值
// 3. 删除最小值(唯一)
// 4. 删除第k个插入的数字
// 5. 修改第k个插入的数字，将其变为x

#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;
int h[N], ph[N], hp[N], sz;

void heap_swap(int a, int b) {
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int x) {
	int t = x;
	if(x * 2 <= sz && h[x * 2] < h[t]) t = x * 2;
	if(x * 2 + 1 <= sz && h[x * 2 + 1] < h[t]) t = x * 2 + 1;
	if(t != x) {
		heap_swap(t, x);
		down(t);
	}
}

void up(int x) {
	while(x / 2 && h[x / 2] > h[x]) {
		heap_swap(x / 2, x);
		x >>= 1;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	int t;
	char op[10];
	while(n--) {
		scanf("%s", op);
		if(!strcmp(op, "I")) {
			int x;
			scanf("%d");
			++t, ++sz, h[sz] = x, ph[t] = sz, hp[sz] = t, up(sz);
		}
		else if(!strcmp(op, "PM")) {
			printf("%d\n", h[1]);
		}
		else if(!strcmp(op, "DM")) {
			heap_swap(1, sz), sz--, down(1);
		}
		else if(!strcmp(op, "D")) {
			int k;
			scanf("%d", &k);
			k = ph[k], heap_swap(k, sz), sz--, down(k), up(k);
		}
		else {
			int k, x;
			scanf("%d%d", &k, &x);
			k = ph[k], h[k] = x, down(k), up(k);
		}
	}
	return 0;
}
