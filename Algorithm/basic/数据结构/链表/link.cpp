// head �洢����ͷ��e[]�洢�ڵ�ֵ, ne[]��nextָ��, idx��ʾ��ǰ���ĸ��ڵ�
int head, e[N], ne[N], idx;

// ��ʼ��
void init() {
	head = -1;
	idx = 0;
}

// ������ͷ������һ����a
void add_to_head(int a) {
	e[idx] = a, ne[idx] = head, head = idx, idx++;
}

// ��x���뵽�±���k�ĵ����
void add(int k, int x) {
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx, idx++;
}


// ��ͷ�ڵ�ɾ��
void remove_head() {
	head = ne[head];
}

// �������
for(int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
