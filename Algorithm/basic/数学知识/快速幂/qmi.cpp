// �����ݣ������ϸ���ָ���Ķ����ƣ��ڸö�����λ��1ʱ�����Է���ƽ���Ľ��

// ��a^b % m, O(logb)
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
