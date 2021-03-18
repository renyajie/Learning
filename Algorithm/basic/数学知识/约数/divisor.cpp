// 试除法求所有约数
vector<int> get_divisors(int x) {
	vector<int> res;
	for(int i = 1; i <= x / i; i++) {
		if(x % i == 0) {
			res.push_back(i);
			if(x / i != i) res.push_back(x / i);
		}
	}
	sort(res.begin(), res.end());
}

// 约数的个数和约数之和
// 如果N = p1^c1 * p2^c2 * .... * pk^ck
// 约数个数：(c1 + 1) * (c2 + 1) * .... * (ck + 1)
// 约数之和: (p1^0 + p1^1 + .. + p1^c1) * ... * (pk^0 + ... + pk^ck)


// 欧几里得算法
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
