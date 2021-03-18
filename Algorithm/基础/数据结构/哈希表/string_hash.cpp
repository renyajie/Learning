// ����˼�룺���ַ�������P�������֣�P�ľ���ֵ��131��13331����ͻ��
// С���ɣ�ȡģ��2^64,ֱ����unsigned long long�洢������Ľ������ȡģ�Ľ��

typedef unsigned long long ULL;
ULL h[N], p[N]; // h[N] ��ǰk����ĸ�Ĺ�ϣֵ��p[k]�洢p^k mod 2^64
int P = 131;

// ��ʼ��
p[0] = 1;
for(int i = 1; i <= n; i++) {
	h[i] = h[i - 1] * P + str[i];
	p[i] = p[i - 1] * P;
}

// �����ִ�str[l ~ r]�Ĺ�ϣֵ
ULL get(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
