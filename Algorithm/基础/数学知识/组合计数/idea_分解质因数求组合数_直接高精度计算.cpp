// 当我们需要求出组合数的真实值，而非对某个数取余时，分解质因数的方式比较好：
// 1. 先通过线性筛法求出范围内所有的质数
// 2. 通过c(a, b) = a! / b! / (a - b)!，求出每个质因子出现的次数，
//    n! 中p的次数是 n / p + n / p^2 + n / p^3 .....
// 3. 用高精度乘法将所有的质因子相乘

int prime[N], cnt; // 存储所有的质数
int st[N]; // 存储每个数字是否已经被筛选掉
int sum[N]; // 存储每个质数出现的个数

void get_prime(int n) // 线性筛法求素数
{
	for(int i = 2; i <= n; i++)
	{
		if(!st[i]) prime[cnt++] = i;
		for(int j = 0; prime[j] <= n / i; j++)
		{
			st[prime[j] * i] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

int get(int n, int p) // 求n!中质因子p的次数
{
	int res = 0;
	while(n)
	{
		res += n / p;
		n /= p;
	}
	return res;
}

vector<int> mul(vector<int> a, int b) // 高精度乘低精度模板
{
	vector<int> c;
	int t = 0;
	for(int i = 0; i < a.size(); i++)
	{
		t = t + a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}

	while(t)
	{
		c.push_back(t % 10);
		t /= 10;
	}

	return c;
}

get_prime(a); // 预出来范围内所有的质数

for(int i = 0; i < cnt; i++)
{
	int p = primes[i];
	sum[i] = get(a, p) - get(b, p) - get(a - b, p);
}

vector<int> res;
res.push_back(1);

for(int i = 0; i < cnt; i++) // 用高精度将所有质因子相乘
{
	for(int j = 0; j < sum[i]; j++)
	{
		res = mul(res, prime[i]);
	}
}

