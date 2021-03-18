// prim�㷨ʱ�临�Ӷ�n^2, �����ڳ���ͼ
int n; // n��ʾ����
int g[N][N]; // �ڽӾ��󣬴洢���б�
int dist[N]; // �洢�����㵽��ǰ��С�������ľ���
bool st[N]; // �洢ÿ�����Ƿ�����������

// ���ͼ����ͨ������INF�����򷵻���С������������Ȩ��֮��
int prim() {
	memset(dist, 0x3f, sizeof dist);

	int res = 0;
	for(int i = 0; i < n; i++) {
		int t = -1;
		for(int j = 1; j <= n; j++) {
			if(!st[j] && (t == -1 || dist[t] > dist[j])) {
				t = j;
			}
		}
			
		st[t] = true;
		if(i && dist[t] == INF) return INF;
		if(i) res += dist[t];
			
		for(int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], g[t][j]);
		}
	}

	return res;
}
