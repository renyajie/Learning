// ��֣������ڶ������޸ĵ��������[l, r]�����ڵ��������ּ���c�������һ�β�ѯ(��β�ѯ���߶���)
// �����ǰ׺�͵������㣬���������ǰ׺�͵õ�ԭ����
// b[1] = a[1], b[2] = a[2] - a[1], b[3] = a[3] - a[2]...


// һά���
// ������[l, r]�е�ÿ�����ּ���c��b[l] += c, b[r + 1] -= c
void insert(int l, int r, int c) {
	b[l] += c;
	b[r + 1] -= c;
}

for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
for(int i = 1; i <= n; i++) insert(i, i, a[i]); // ������
while(m--) {
	int l, r, c;
	scanf("%d%d%d", &l, &r, &c);
	insert(l, r, c); // ��ֲ���
}
for(int i = 1; i <= n; i++) b[i] += b[i - 1]; // �ָ��������������ԭ����


// ��ά���
// ��(x1, y1)Ϊ���Ͻǣ�(x2, y2)Ϊ���½ǵ��Ӿ��������Ԫ�ؼ���c��
// S[x1][y1] += c; S[x2 + 1][y1] -= c; S[x1][y2 + 1] -= c; s[x2 + 1][y2 + 1] += c;

void insert(int x1, int y1, int x2, int y2, int c) {
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= m; j++) {
		scanf("%d", &a[i][j]);
	}
}

for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= m; j++) {
		insert(i, j, i, j, a[i][j]); // �����ά���
	}
}

while(q--) {
	int x1, y1, x2, y2, c;
	scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
	insert(x1, y1, x2, y2, c); // ��ֲ���
}

for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= m; j++) {
		b[i][j] += b[i-1][j] + b[i][j - 1] - b[i-1][j-1]; // �ָ��������������ԭ����
	}
}
