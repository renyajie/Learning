bool check(int x) { /* ... */ } //���x�Ƿ�����ĳ������

// ������������ƶ�R�������Ұ�����������
int bsearch_1(int l, int r) {
	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	return l'
}

// ���ұ��������ƶ�L�������������������
int bsearch_2(int l, int r) {
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}
