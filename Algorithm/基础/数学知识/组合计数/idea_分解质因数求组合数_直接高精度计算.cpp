// ��������Ҫ������������ʵֵ�����Ƕ�ĳ����ȡ��ʱ���ֽ��������ķ�ʽ�ȽϺã�
// 1. ��ͨ������ɸ�������Χ�����е�����
// 2. ͨ��c(a, b) = a! / b! / (a - b)!�����ÿ�������ӳ��ֵĴ�����
//    n! ��p�Ĵ����� n / p + n / p^2 + n / p^3 .....
// 3. �ø߾��ȳ˷������е����������

int prime[N], cnt; // �洢���е�����
int st[N]; // �洢ÿ�������Ƿ��Ѿ���ɸѡ��
int sum[N]; // �洢ÿ���������ֵĸ���

void get_prime(int n) // ����ɸ��������
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

int get(int n, int p) // ��n!��������p�Ĵ���
{
	int res = 0;
	while(n)
	{
		res += n / p;
		n /= p;
	}
	return res;
}

vector<int> mul(vector<int> a, int b) // �߾��ȳ˵;���ģ��
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

get_prime(a); // Ԥ������Χ�����е�����

for(int i = 0; i < cnt; i++)
{
	int p = primes[i];
	sum[i] = get(a, p) - get(b, p) - get(a - b, p);
}

vector<int> res;
res.push_back(1);

for(int i = 0; i < cnt; i++) // �ø߾��Ƚ��������������
{
	for(int j = 0; j < sum[i]; j++)
	{
		res = mul(res, prime[i]);
	}
}

