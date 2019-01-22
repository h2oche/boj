//https://www.acmicpc.net/problem/10844
#include <iostream>
#define M 1000000000
using namespace std;

int N;
long long dp[10] = { 1, 1, 2, 2, 2, 2, 2, 2, 2, 1 };
long long buf[10] = { 0, };

long long solve(void) {
	long long sum = 0;
	for (int i = 0; i < 10; i += 1) sum += (dp[i] % M);
	return sum % M;
}

void copy() {
	for (int i = 0; i < 10; i += 1) buf[i] = dp[i];
}

int main(void) {
	cin >> N;
	if (N == 1) cout << 9;
	else {
		for (int i = 2; i < N; i += 1) {
			copy();
			dp[0] = buf[1];
			for (int j = 1; j < 9; j += 1)
				dp[j] = (buf[j - 1] % M + buf[j + 1] % M);
			dp[9] = buf[8];
		}
		cout << solve();
	}
	return 0;
}
