// bellman-ford�������ڸ���ߣ�Ч��Ϊnm������spfa�������б������Ƶĸ�������·ֻ��������㷨

struct Edge {
	int a, b, w;
} e[M]; // �����

int dist[N], back[N]; // ���������ֹ����
int n, m, k; // k�������·������k����

int bellman_ford() {
	memset(dist, 0x3f3f3f3f, sizeof dist);
	dist[1] = 0;
	for(int i = 0; i < k; i++) { // k��ѭ��
		memcpy(back, dist, sizeof dist);
		for(int j = 0; j < m; j++) {
			int a = e[j].a, b = e[j].b, w = e[j].w;
			dist[b] = min(dist[b], back[a] + w); // ����������£�������
		}
	}

	if(dist[n] > 0x3f3f3f3f / 2) return -1;
	return dist[n];
}
