#include<iostream>
#include<unordered_map>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);

	int res = 0;
	unordered_map<int,int> mp;
	for(int i = 0, j = 0; i < n; i++) {
		mp[a[i]]++;
		while(j < i && mp[a[i]] > 1) {
			mp[a[j]]--;
			j++;
		}
		res = max(res, i - j + 1);
	}

	printf("%d", res);
	return 0;
}
