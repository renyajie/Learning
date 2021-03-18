// 试除法判定质数
bool is_prime(int x) {
	if(x < 2) return false;
	for(int i = 2; i <= n / i; i++) {
		if(x % i == 0) {
			return false;
		}
	}

	return true;
}

// 试除法分解质因数
void divide(int x) {
	for(int i = 2; i <= x / i; i++) {
		if(x % i == 0) {
			int s = 0;
			while(x % i == 0) x /= i, s++;
			printf("%d %d\n", i, s);
		}
	}
	if(x > 1) printf("%d 1\n", x);
}

// 朴素筛法求素数
int prime[N], cnt; // prime[]存储所有素数
bool st[N]; // 存储每个数是否被筛选过

void get_primes(int n) {
	for(int i = 2; i <= n / i; i++) {
		if(st[i]) continue;
		primes[cnt++] = i;
		for(int j = i + i; j <= n; j += i) {
			st[j] = true;
		}
	}
}


// 线性筛法求素数
int prime[N], cnt;
bool st[N];

void get_primes(int n) {
	for(int i = 2; i <= n; i++) {
		if(!st[i]) prime[cnt++] = i;
		for(int j = 0; prime[j] <= n / i; j++) {
			st[prime[j] * i] = true;
			if(i % prime[j] == 0) break;
		}
	}
}
