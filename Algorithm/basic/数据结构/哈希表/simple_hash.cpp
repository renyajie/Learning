// 开放寻址法
const int null = 0x3f3f3f3f; 

int h[N];
memset(h, 0x3f, sizeof h);

// 如果x在哈希表中返回下标，如果不在，返回应该插入的位置
int find(int x) {
	int t = (x % N + N) % N;
	while(h[t] != null && h[t] != x) {
		t++;
		if(t == N) t = 0;
	}
	return x;
}
