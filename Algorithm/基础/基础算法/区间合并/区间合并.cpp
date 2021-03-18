#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;

void merge(vector<PII> &segs) {
	vector<PII> res;
	sort(segs.begin(), segs.end());
	int st = -2e9, ed = -2e9;
	for(auto seg : segs) {
		if(ed < seg.first) {
			if(st != -2e9) res.push_back({st, ed});
			st = seg.first, ed = seg.second;
		}
		else ed = max(ed, seg.second);
	}
	if(st != -2e9) res.push_back({st, ed});
	segs = res;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<PII> segs;
	while(n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		segs.push_back({a, b});
	}

	merge(segs);

	printf("%d", segs.size());
	return 0;
}
