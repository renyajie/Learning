// ���ز��鼯
// *********************
int p[N]; // �洢ÿ���ڵ�����ڸ���

// ����x�����ڽڵ�
int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

// ��ʼ�����ٶ��ڵ�����1~n
for(int i = 1; i <= n; i++) p[i] = i;

// �ϲ�a��b���ڵ���������
p[find(a)] = find(b);



// ά�����ϸ����Ĳ��鼯
// *********************
int p[N], size[N]; // size��ʾÿ�������ڼ��ϵ�Ԫ�ظ�����ֻ�и��ڵ�������

// ����x�����ڽڵ�
int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

// ��ʼ�����ٶ��ڵ�����1~n
for(int i = 1; i <= n; i++) {
	p[i] = i, size[i] = 1;
}

// �ϲ�a��b���ڵ���������
size[find(b)] += size[find(a)];
p[find(a)] = find(b);


// ά�������Ƚڵ����Ĳ��鼯
// **********************

int p[N], d[N]; //d[x]�洢x��p[x]�ľ���

// ����x�����Ƚڵ�
int find(int x) {
	if(p[x] != x) {
		int u = find(p[x]);
		d[x] += d[p[x]];   // �ڽ���·��ѹ��֮ǰ���ۼӾ���
		p[x] = u;
	}
	return p[x];
}

// ��ʼ�����ٶ��ڵ�����1~n
for(int i = 1; i <= n; i++) {
	p[i] = i, d[i] = 0;
}

// �ϲ�a��b���ڵ���������
p[find(a)] = find(b);
d[find(a)] = distance; // ���ݾ�������⣬��ʼ��


