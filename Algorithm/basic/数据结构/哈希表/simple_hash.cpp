// ����Ѱַ��
const int null = 0x3f3f3f3f; 

int h[N];
memset(h, 0x3f, sizeof h);

// ���x�ڹ�ϣ���з����±꣬������ڣ�����Ӧ�ò����λ��
int find(int x) {
	int t = (x % N + N) % N;
	while(h[t] != null && h[t] != x) {
		t++;
		if(t == N) t = 0;
	}
	return x;
}
