// �Գ���������Լ��
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

// Լ���ĸ�����Լ��֮��
// ���N = p1^c1 * p2^c2 * .... * pk^ck
// Լ��������(c1 + 1) * (c2 + 1) * .... * (ck + 1)
// Լ��֮��: (p1^0 + p1^1 + .. + p1^c1) * ... * (pk^0 + ... + pk^ck)


// ŷ������㷨
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
