// spfa һ�㸴�Ӷ�m, ����Ӷ�(nm)������ߺ�����㶼����
// ������ڸ���·����ѭ����һ��ÿ���cnt���ж�

int n; // �ܵ���
int h[N], e[N], ne[N], w[N], idx; // �ڽӱ�
int dist[N]; // �洢ÿ���㵽1�ŵ�ľ���
bool st[N]; // �洢ÿ�����Ƿ��ڶ�����

// ��1�ŵ㵽n�ŵ����̾��룬���1�ŵ��޷��ߵ�n�ŵ㷵��-1
int spfa() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	queue<int> q;
	q.push(1);
	st[1] = true;

	while(q.size()) {
		auto t = q.front(); 
		q.pop();

		st[t] = false;

		for(int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if(!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}

	if(dist[n] > 0x3f3f3f3f / 2) return -1;
	return dist[n];
}
