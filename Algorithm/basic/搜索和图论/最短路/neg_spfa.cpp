// spfa�жϸ���
int n; // �ܵ���
int h[N], e[N], ne[N], w[N], idx; // �ڽӱ�洢���еı�
int dist[N], cnt[N]; // dist[x]�洢1�ŵ㵽x����̾��룬 cnt[x]��ʾ��x�����·�ı���
bool st[N]; // ÿ�����Ƿ��ڶ�����

// ������ڸ���������true�����򷵻�false
bool spfa() {
	
	// ����Ҫ��ʼ��dist����
	// ԭ�������ĳ�����·��n����(�����Լ�)����ô�����Լ�n+1�����ʱ���2������ͬ==������

	queue<int> q;
	for(int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = true;
	}

	while(q.size()) {
		auto t = q.front();
		q.pop();

		st[t] = false;
		for(int i = h[t]; i != -1' i = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if(cnt[j] >= n) return true; // ���1�ŵ㵽x�����·���ٰ���n+1�������и���
				if(!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}

		return false;
	}
}
