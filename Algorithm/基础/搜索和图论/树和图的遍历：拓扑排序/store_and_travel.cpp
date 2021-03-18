// ����ͼ�Ĵ洢��ʽ��ͬ
// �ڽӾ���g[a][b] �洢a->b

// �ڽӱ�
// ����ÿһ����k����һ���������洢k���п����ߵ��ĵ㡣h[k]�洢����������ͷ�ڵ�
int h[N], e[N], ne[N], idx;

// ���һ����a->b
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// ��ʼ��
idx = 0;
memset(h, -1, sizeof h);

// **********************************
// ����ͼ�ı���
// ʱ�临�Ӷ�O(n+m)��n��ʾ������m��ʾ����
// 1. ������ȱ���
int dfs(int u) {
	st[u] = true; // st[u]��ʾ��i�Ѿ���������
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[j];
		if(!st[j]) dfs(j);
	}
}

// 2. ������ȱ���
queue<int> q;
st[1] = true; // ��ʾ1�ŵ��Ѿ���������
q.push(1);

while(q.size()) {
	int t = q.front();
	q.pop();

	for(int i = h[t]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			st[j] = true;
			q.push(j);
		}
	}
}
