// �������г���ģ�ͣ��ҳ����������е����ֵ/��Сֵ
int q[N], hh = 0, tt = -1;
for(int i = 0; i < n; i++) {
	while(hh <= tt && check(q[hh])) hh++; // �ж϶�ͷ�Ƿ񻬳�����
	while(hh <= tt && check(q[tt], i)) tt--;
	q[++tt] = i;
}
