#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

const int N = 20, P = 1e9 + 7;

struct F
{
    int s0, s1, s2; // s0： 符合要求的个数， s1：符合数字的和, s2：符合数字的平方和
} f[N][10][7][7]; // i位数，最高位是j，数字和模7是a，整数模7是b的集合 {}

int power9[N];
int power7[N];


int mod(ll a, int b)
{
    return (a % b + b) % b;
}

void init()
{
    
    for(int i = 0; i < 10; i++)
    {
        if(i == 7) continue;
        auto &v = f[1][i][mod(i, 7)][mod(i, 7)];
        v.s0++;
        v.s1 += i;
        v.s2 += i * i;
    }
    
    ll power = 10;
    for(int i = 2; i < N; i++, power *= 10)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j == 7) continue;
            for(int a = 0; a < 7; a++)
            {
                for(int b = 0; b < 7; b++)
                {
                    for(int k = 0; k < 10; k++)
                    {
                        if(k == 7) continue;
                        auto &v1 = f[i][j][a][b], &v2 = f[i - 1][k][mod(a - j * power, 7)][mod(b - j, 7)];
                        v1.s0 = mod(v1.s0 + v2.s0, P);
                        v1.s1 = mod(v1.s1 + v2.s1 + j * (power % P) % P * v2.s0, P);
                        v1.s2 = mod(v1.s2 + j * j * (power % P) % P * (power % P) % P * v2.s0 + v2.s2 + 2 * j * power % P * v2.s1, P);

                    }
                }
            }
        }
    }
    
    power7[0] = 1;
    for (int i = 1; i < N; i ++ ) power7[i] = power7[i - 1] * 10 % 7;

    power9[0] = 1;
    for (int i = 1; i < N; i ++ ) power9[i] = power9[i - 1] * 10ll % P;
}

F get(int i, int j, int a, int b)
{
    int s0 = 0, s1 = 0, s2 = 0;
    for (int x = 0; x < 7; x ++ )
        for (int y = 0; y < 7; y ++ )
            if (x != a && y != b)
            {
                auto v = f[i][j][x][y];
                s0 = (s0 + v.s0) % P;
                s1 = (s1 + v.s1) % P;
                s2 = (s2 + v.s2) % P;
            }
    return {s0, s1, s2};
}
    
int dfs(ll n)
{
    if(!n) return 0;
    
    ll back_n = n % P;
    
    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10;
    
    int ans = 0;
    ll last_a = 0; // 前面整数
    ll last_b = 0; // 前面数位和
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for(int j = 0; j < x; j++)
        {
            if(j == 7) continue;
            int b = mod(-last_b, 7);
            int a = mod(-last_a * power7[i + 1], 7);
            F v = get(i + 1, j, a, b);
            ans = mod(
                ans + 
                (last_a % P) * (last_a % P) % P * power9[i + 1] % P * power9[i + 1] % P * v.s0 % P + 
                v.s2 + 
                2 * last_a % P * power9[i + 1] % P * v.s1,
            P);
        }
        
        if(x == 7) break;
        
        last_b += x;
        last_a = last_a * 10 + x;
        
        if(!i && mod(last_a, 7) != 0 && mod(last_b, 7) != 0) ans = mod(ans + back_n * back_n, P); 
    }
    
    return ans;
}

int main()
{
    init();
    
    int T; scanf("%d", &T);
    while(T--)
    {
        ll a, b; scanf("%lld%lld", &a, &b);
        printf("%d\n", mod(dfs(b) - dfs(a - 1), P));
    }
    
    return 0;
}
