// s[]�ǳ��ı���p[]��ģʽ����n��s�ĳ��ȣ�m��p�ĳ���
// ע���±궼��1��ʼ, ne[1] = 0;


// ���next����
for(int i = 2, j = 0; i <= m; i++) {
	while(j && p[i] != p[j + 1]) j = ne[j];
	if(p[i] == p[j + 1]) j++;
	ne[i] = j;
}

// ƥ��
for(int i = 1, j = 0; i <= n; i++) {
	while(j && s[i] != p[j + 1]) j = ne[j];
	if(s[i] == p[j + 1]) j++;
	if(j == m) {
		j = ne[j];
		// ƥ��ɹ�����߼�
	}
}
