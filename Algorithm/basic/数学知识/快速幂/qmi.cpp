// 快速幂：本质上根据指数的二进制，在该二进制位是1时，乘以反复平方的结果

// 求a^b % m, O(logb)
int qmi(int a, int b, int m)
{
	int res = 1, t = a;
	while(b)
	{
		if(b & 1) res = res * t % m;
		t = t * t % m;
		b >>= 1;
	}

	return res;
}
