// 一个无限长的数轴，上面的数字都是0，先进行n此操作，每次将某一位置上的数字+c，接下来进行m次查询，求出区间[l, r]之间所有数字的和

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 3e5 + 10;
int n, m;
int a[N], b[N];

typedef pair<int,int> PII;
vector<int> alls;
vector<PII> adds;
vector<PII> queries;

int find(int x) {
	int l = 0, r = alls.size() - 1;
	while(l < r) {
		int mid = l + r >> 1;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l + 1;
}

int main() {
	scanf("%d%d", &n, &m);
	while(n--) {
		int x, c;
		scanf("%d%d", &x, &c);
		alls.push_back(x); // 保存有效位置
		adds.push_back({x, c}); // 记录加操作
	}
	while(m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		alls.push_back(l); // 保存有效位置
		alls.push_back(r); //
		queries.push_back({l, r}); // 记录查询操作
	}

	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	for(auto item : adds) a[find(item.first)] += item.second; // 构造新数组

	for(int i = 1; i <= alls.size(); i++) b[i] = b[i - 1] + a[i];

	for(auto item : queries) {
		int l = find(item.first), r = find(item.second);
		printf("%d\n", b[r] = b[l - 1];)
	}
	return 0;
}
