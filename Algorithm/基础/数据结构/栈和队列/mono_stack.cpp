// ����ջ����ģ�ͣ��ҳ�ÿ�����������������ı���С/�������

int st[N], tt = 0;
for(int i = 1; i <= n; i++) {
	while(tt && check(st[tt], i)) tt--;
	st[++tt] = i;
}
