// 适用于NlogP能接受的范围，P为模数，N是数字范围
// 首先预处理出来所有阶乘的余数fact[N]，以及所有阶乘取模的逆元infact[N]
// 如果取模的数是质数，可以用费马小定理求逆元
int qmi(int a, int b, int m)
{
	int res = 1;
	while(b)
	{
		if(b & 1) res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

// 预处理阶乘的余数和阶乘的逆元的余数
fact[0] = infact[0] = 1;
for(int i = 1; i < N; i++)
{
	fact[i] = (ll)fact[i - 1] * i % mod;
	infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod
}

// c[a][b] == fact[a] * infact[a - b] % mod * infact[b] % mod

