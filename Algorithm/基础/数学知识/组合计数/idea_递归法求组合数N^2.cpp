// c[a][b]表示从a个苹果中选择b个苹果的方案数
// 适用于N^2可以接受的情况
for(int i = 0; i < N; i++)
{
	for(int j = 0; j <= i; j++)
	{
		if(j == 0) c[i][j] = 1;
		c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
}
