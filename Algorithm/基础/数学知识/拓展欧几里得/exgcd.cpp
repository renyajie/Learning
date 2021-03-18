// 拓展欧几里得算法，求x,y，使得ax + by = gcd(a, b) (1)
// 在欧几里得求最大公约数的基础上，可以顺便求出x, y的值
// 只属于为何一定存在(1)，就是斐蜀定理
// 若问ax + by = d是否有解，等价于问d是不是gcd(a,b)的倍数

// 求x, y，使得ax + by = gcd(a, b)
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
