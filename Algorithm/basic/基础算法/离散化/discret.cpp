// ������ַ�Χ�ܴ󣬵��ǲ����ĺ��٣��Ƚ�ϡ�裬�����Ȱ����õ�����ȡ��
// ��ȥ�أ�֮���ö��ֲ�����Ҫ�����ּ���

vector<int> alls; // �洢���д���ɢ����λ��
sort(alls.begin(), alls.end()); // �����е�λ������
alls.erase(unique(alls.begin(), alls.end()), alls.end()); // ȥ���ظ�Ԫ��

// �������x[ԭʼλ��]��Ӧ����ɢ�����λ��
int find(int x) {
	int l = 0, r = alls.size() - 1;
	while(l < r) {
		int mid = l + r >> 1;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1; // ӳ�䵽1, 2, 3....., n
}
