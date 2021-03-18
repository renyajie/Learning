// ���Ż���Dijkstra������������ߣ�ϡ��ͼ
typedef pair<int,int> PII;

int n; // �������
int h[N], e[N], ne[N], w[N], idx; // �ڽӱ�洢���б�
int dist[N]; // �洢���е㵽1�ŵ�ľ���
bool st[N]; // �洢ÿ�������̾����Ƿ�ȷ��

int dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});

	while(heap.size()) {
		auto t = heap.top();
		heap.pop();

		int id = t.second, distance = t.first;
		if(st[id]) continue;
		st[id] = true;

		for(int i = h[id]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] > distance + w[i]) {
				dist[j] = distance + w[i];
				heap.push({dist[j], j});
			}
		}
	}

	if(dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}
