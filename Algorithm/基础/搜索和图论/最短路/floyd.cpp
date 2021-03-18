// floyd�㷨 n^3����Դ���·����Ȩ�Ǹ���Ҳû�£��ж�0x3f3f3f3f / 2����

// ��ʼ��
for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= n; j++) {
		if(i == j) d[i][j] = 0;
		else d[i][j] = INF;
	}
}

// �㷨������d[a][b]��ʾa��b����̾���
void floyd() {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
