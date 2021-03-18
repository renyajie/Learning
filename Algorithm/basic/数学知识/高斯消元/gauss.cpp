// 高斯消元法
// 对每一列：
//		1. 找到当前列最大的行
//    2. 将最大的行交换到(还没确定的第一行)
//    3. 将该行该列的系数变为1
//    4. 用当前行将下面所有的列消成0
// 
// 判断经过的行数，
//  1. 行数r<n：
//		1. 如果r行之后有非0值存在，无解，返回2
//    2. 否则有无穷多组解，返回1
//	2. 有唯一解
//  此时矩形已经是处理好，从最后一行开始，依次减去系数即可
//  返回0

// a[N][N]是增广矩阵
int gauss()
{
	int r, c;
	for(c = 0, r = 0; c < n; c++)
	{
		int t = r;
		for(int i = r + 1; i < n; i++)  // 找到绝对值最大的行
		{
			if(fabs(a[i][c]) > fabs(a[t][c])) t = i;
		}
		if(fabs(a[t][c]) < eps) continue;

		for(int i = c; i <= n; i++) swap(a[t][i], a[r][i]); // 将绝对值最大的放在最上面
		for(int i = n; i >= c; i--) a[r][i] / = a[r][c]; // 将首位的系数变成1
		for(int i = r + 1; i < n; i++) // 将下面的行的该列系数变成0
		{
			for(int j = n; j >= c; j--)
			{
				a[i][j] -= a[i][c] * a[r][j];
			}
		}
		
		r++;
	}

	if(r < n)
	{
		for(int i = r; i < n; i++)
		{
			if(fabs(a[i][n]) > eps) return 2; // 出现0 = 数字，无解
		}
		return 1; // 无穷多组解
	}

	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = i + 1; j < n; j++)
		{
			a[i][n] -= a[i][j] * a[j][n];  // 只保留主对角线，利用下面的行
		}
	}

	return 0; // 有唯一解
}
