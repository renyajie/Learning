// head 存储链表头，e[]存储节点值, ne[]存next指针, idx表示当前到哪个节点
int head, e[N], ne[N], idx;

// 初始化
void init() {
	head = -1;
	idx = 0;
}

// 在链表头部插入一个数a
void add_to_head(int a) {
	e[idx] = a, ne[idx] = head, head = idx, idx++;
}

// 将x插入到下标是k的点后面
void add(int k, int x) {
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx, idx++;
}


// 将头节点删除
void remove_head() {
	head = ne[head];
}

// 链表遍历
for(int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
