// 如果数字范围很大，但是操作的很少，比较稀疏，可以先把有用的数字取出
// 并去重，之后用二分查找需要的数字即可

vector<int> alls; // 存储所有带离散化的位置
sort(alls.begin(), alls.end()); // 将所有的位置排序
alls.erase(unique(alls.begin(), alls.end()), alls.end()); // 去掉重复元素

// 二分求出x[原始位置]对应的离散化后的位置
int find(int x) {
	int l = 0, r = alls.size() - 1;
	while(l < r) {
		int mid = l + r >> 1;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1; // 映射到1, 2, 3....., n
}
