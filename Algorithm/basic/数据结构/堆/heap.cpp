// С����Ϊ��
// 1. ����һ����           heap[++size] = x; up(size);
// 2. �󼯺��е���Сֵ     heap[1];
// 3. ɾ����Сֵ           heap[1] = heap[size]; size--; down(1);
// 4. ɾ������һ��Ԫ��     heap[k] = heap[size]; size--; down(k); up(k);
// 5. �޸�����һ��Ԫ��     heap[k] = x; down(k); up(k);


// h[N]�洢���е�ֵ��h[1]�ǶѶ�, x���������2x���Ҷ�����2x+1
// ph[k]�洢��k������ĵ��ڶ��е�λ��
// hp[k]�洢�����±���k�ĵ��ǵڼ��������

int h[N], ph[N], hp[N], size;

// �������е������㣬�Ͷ�Ӧӳ���ϵ
void heap_swap(int a, int b) {
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

// ��u���µ���
void down(int u) {
	int t = u;
	if(u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
	if(u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
	if(u != t) {
		heap_swap(u, t);
		down(t);
	}
}

// ��u���ϵ���
void up(int u) {
	while(u / 2 && h[u] < h[u / 2]) {
		heap_swap(u, u / 2);
		u >>= 1;
	}
}

// O(n) ����
for(int i = n / 2; i; i--) down(i);
