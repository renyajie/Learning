// kruskal������ϡ��ͼ��ʱ�临�ӷ�mlogm
int n, m; // n�ǵ�����m�Ǳ���
int p[N]; // ���鼯�ĸ��ڵ�����

struct edge {
	int a, b, w;

	bool operator< (const edge &W) const {
		return w < W.w;
	}
} e[M];

int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int kruskal() {
	sort(e, e + m);

	for(int i = 1; i <= n; i++) p[i] = i;

	int res = 0, cnt = 0;
	for(int i = 0; i < m; i++) {
		int a = e[i].a, b = e[i].b, w = e[i].w;
		
		a = find(a), b = find(b);
		if(a != b) { // ���������ͨ�鲻��ͨ������������ͨ��ϲ�
			p[a] = b;
			res += w;
			cnt++;
		}
	}

	if(cnt < n - 1) return INF;
	return res;
}
