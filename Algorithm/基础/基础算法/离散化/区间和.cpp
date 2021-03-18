// һ�����޳������ᣬ��������ֶ���0���Ƚ���n�˲�����ÿ�ν�ĳһλ���ϵ�����+c������������m�β�ѯ���������[l, r]֮���������ֵĺ�

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
		alls.push_back(x); // ������Чλ��
		adds.push_back({x, c}); // ��¼�Ӳ���
	}
	while(m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		alls.push_back(l); // ������Чλ��
		alls.push_back(r); //
		queries.push_back({l, r}); // ��¼��ѯ����
	}

	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	for(auto item : adds) a[find(item.first)] += item.second; // ����������

	for(int i = 1; i <= alls.size(); i++) b[i] = b[i - 1] + a[i];

	for(auto item : queries) {
		int l = find(item.first), r = find(item.second);
		printf("%d\n", b[r] = b[l - 1];)
	}
	return 0;
}
