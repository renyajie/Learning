// ��չŷ������㷨����x,y��ʹ��ax + by = gcd(a, b) (1)
// ��ŷ����������Լ���Ļ����ϣ�����˳�����x, y��ֵ
// ֻ����Ϊ��һ������(1)�����������
// ����ax + by = d�Ƿ��н⣬�ȼ�����d�ǲ���gcd(a,b)�ı���

// ��x, y��ʹ��ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y)
{
	if(!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y = y - (a / b) * x;
	return d;
}
