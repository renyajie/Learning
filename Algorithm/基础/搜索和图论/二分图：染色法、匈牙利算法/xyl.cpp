// �������㷨O(nm)��ʹ�ü������ͼ�����ƥ��
int n1, n2; // n1��ʾ��һ�������еĵ�����n2��ʾ�ڶ��������еĵ���
int h[N], e[N], ne[N], idx;
int match[N]; // �ڶ���������ÿ���㵱ǰƥ��ĵ�һ�������ĸ�
bool st[N]; // �ڶ��������е�ÿ�����Ƿ��Ѿ���������

bool find(int x) {
	for(int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			st[j] = true;
			if(match[j] == 0 || find(match[j])) {
				match[j] = x;
				return true;
			}
		}
	}

	return false;
}

// �����ƥ������ ����ö��ÿ�����ܷ�ƥ��ڶ��������еĵ�
int res = 0;
for(int i = 1; i <= n1; i++) {
	memset(st, false, sizeof st);
	if(find(i)) res++;
}
