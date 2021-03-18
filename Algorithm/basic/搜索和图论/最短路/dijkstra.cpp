// ����Dijkstra�㷨�����������ߣ�����ͼ
// һ�����ͼ���ߵ�����m=n^2
int g[N][N]; // �洢ÿ����
int dist[N]; // �洢1�ŵ㵽ÿ�������̾���
bool st[N]; // �洢ÿ��������·���Ƿ��Ѿ�ȷ��

// ��1�ŵ㵽n�ŵ�����·������������򷵻�-1
int dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	for(int i = 0; i < n - 1; i++) {
		int t = -1; // �ڻ�ûȷ�����·�ĵ���Ѱ�Ҿ�����С��
		for(int j = 1; j <= n; j++) {
			if(!st[j] && (t == 1 || dist[t] > dist[j])) {
				t = j;
			}
		}

		// ��t����������ľ���
		for(int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		}

		st[t] = true;
	}

	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}
