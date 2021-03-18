// 小根堆为例
// 1. 插入一个数           heap[++size] = x; up(size);
// 2. 求集合中的最小值     heap[1];
// 3. 删除最小值           heap[1] = heap[size]; size--; down(1);
// 4. 删除任意一个元素     heap[k] = heap[size]; size--; down(k); up(k);
// 5. 修改任意一个元素     heap[k] = x; down(k); up(k);


// h[N]存储堆中的值，h[1]是堆顶, x的左儿子是2x，右二子是2x+1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的

int h[N], ph[N], hp[N], size;

// 交换堆中的两个点，和对应映射关系
void heap_swap(int a, int b) {
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

// 将u向下调整
void down(int u) {
	int t = u;
	if(u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
	if(u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
	if(u != t) {
		heap_swap(u, t);
		down(t);
	}
}

// 将u向上调整
void up(int u) {
	while(u / 2 && h[u] < h[u / 2]) {
		heap_swap(u, u / 2);
		u >>= 1;
	}
}

// O(n) 建堆
for(int i = n / 2; i; i--) down(i);
