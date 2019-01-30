#include <iostream>
using namespace std;
#define MAX_N 4000001
#define P 1000000007

long long dp[MAX_N] = { 0, };
int n, k;

long long exp(long long x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	long long a = exp(x, n / 2);
	if (n % 2 == 0) return (a * a) % P;
	else return ((a * a) % P * x) % P;
}

int main(void) {
	cin >> n >> k;
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] * i) % P;

	long long k_inv = exp(dp[k], P - 2);
	long long nmk_inv = exp(dp[n - k], P - 2);

	cout << (((k_inv * nmk_inv) % P) * dp[n]) % P;
	return 0;
}
