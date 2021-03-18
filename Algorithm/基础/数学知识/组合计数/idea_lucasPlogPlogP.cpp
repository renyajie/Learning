// 如果p是质数，则对于任意整数 1 <= m <= n，有：
// C(n,m) = c(n % p, m % p) * C(n / p, m / p) (mod p)
// 适用于a和b特别大，但是模数p不大的情况

int qmi(int a, int b, int m)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = (ll)res * a % m;
		a = (ll)a * a % m;
		b >>= 1;
	}
	return res;
}

int C(int a, int b) // 通过定义求组合数C(a,b) % p
{
	int res = 1;
	for(int i = 1, j = a; i <= b; j--, i++)
	{
		res = (ll)res * j % p;
		res = (ll)res * qmi(i, p - 2, p) % p;
	}
	return res;
}

int lucas(ll a, ll b)
{
	if(a < p && b < p) return C(a, b);
	return (ll) lucas(a % p, b % p) * lucas(a / p, b / p) % p;
}
