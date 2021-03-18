// ŷ��������1~N�к�N���ʵĸ���(gcd(N,x)==1��x�ĸ���)����ΪN��ŷ������
// f(N) = N(1 - 1/p1)(1 - 1/p2)...(1 - 1/pk), pΪN��������
// ŷ����������:
// ��a��n���ʣ���a^f(n) = 1 mod n
// ��nΪ����ʱ��Ϊf(n)=n-1�����Ƿ�����: a^(n-1) = 1 mod n

// ��һ������ŷ������
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

// ��������ɸ��һ�������1~N�������ֵ�ŷ������
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
