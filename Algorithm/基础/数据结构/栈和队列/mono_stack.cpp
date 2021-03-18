// 单调栈常见模型：找出每个数字左边离它最近的比它小/大的数字

int st[N], tt = 0;
for(int i = 1; i <= n; i++) {
	while(tt && check(st[tt], i)) tt--;
	st[++tt] = i;
}
