// 欧拉函数：1~N中和N互质的个数(gcd(N,x)==1的x的个数)，成为N的欧拉函数
// f(N) = N(1 - 1/p1)(1 - 1/p2)...(1 - 1/pk), p为N的质因数
// 欧拉函数性质:
// 若a和n互质，则a^f(n) = 1 mod n
// 当n为质数时，为f(n)=n-1，就是费马定理: a^(n-1) = 1 mod n

// 求一个数的欧拉函数
int phi(int x) 
{
	int res = x;
	for(int i = 2; i <= x / i; i++)
	{
		if(x % i == 0)
		{
			res = res / i * (i - 1);
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) res = res / x * (x - 1);
	
	return res;
}

// 利用线性筛法一次性求出1~N所有数字的欧拉函数
int prime[N], cnt;
bool st[N];
int euler[N];

void get_eulers(int n)
{
	euler[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!st[i]) 
		{
			prime[cnt++] = i;
			euler[i] = i - 1;
		}
		for(int j = 0; prime[j] <= n / i; j++)
		{
			int t = prime[j] * i;
			st[t] = true;
			if(i % prime[j] == 0) 
			{
				euler[t] = euler[i] * prime[j];
				break;
			}
			euler[t] = euler[i] * (prime[j] - 1);
		}
	}
}
