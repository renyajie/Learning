// e[]��ʾ�ڵ��ֵ��l[]��ʾ��ָ��, r[]��ʾ��ָ��, idx��ʾ��ǰ�õ��ĸ���
int e[N], l[N], r[N], idx;

// ��ʼ��
void init() {
	// 0����˵㣬1���Ҷ˵�
	r[0] = 1, l[1] = 0;
	idx = 2;
}

// �ڽڵ�a���ұ߲���һ����
void insert(int a, int x) {
	e[idx] = x;
	l[idx] = a, r[idx] = r[a];
	l[r[a]] = idx, r[a] = idx;
	idx++;
}

// ɾ���ڵ�a
void remove(int a) {
	l[r[a]] = l[a];
	r[l[a]] = r[a];
}


