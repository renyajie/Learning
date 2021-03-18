// ������NlogP�ܽ��ܵķ�Χ��PΪģ����N�����ַ�Χ
// ����Ԥ����������н׳˵�����fact[N]���Լ����н׳�ȡģ����Ԫinfact[N]
// ���ȡģ�����������������÷���С��������Ԫ
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

// Ԥ����׳˵������ͽ׳˵���Ԫ������
fact[0] = infact[0] = 1;
for(int i = 1; i < N; i++)
{
	fact[i] = (ll)fact[i - 1] * i % mod;
	infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod
}

// c[a][b] == fact[a] * infact[a - b] % mod * infact[b] % mod

