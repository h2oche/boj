#include <iostream>
#include <cmath>
#define M 1000000000
#define DIGITS 10
#define MASK(d) (1 << (d))
using namespace std;

int N;
long long dp[DIGITS][1 << DIGITS] = { 0, };
long long buf[DIGITS][1 << DIGITS] = { 0, };

void copy_and_clear() {
	for (int i = 0; i < DIGITS; i += 1)
		for (int j = 0; j < 1 << DIGITS; j += 1)
			buf[i][j] = dp[i][j], dp[i][j] = 0;
}

void init() {
	for (int i = 0; i < DIGITS - 1; i += 1)
		dp[i][MASK(i) | MASK(i + 1)]++;
	for (int i = 2; i < DIGITS; i += 1)
		dp[i][MASK(i) | MASK(i - 1)]++;
}

long long get_ans() {
	long long sum = 0;
	for (int i = 0; i < DIGITS; i += 1)
		sum = (sum + dp[i][(1 << DIGITS) - 1]) % M;
	return sum % M;
}

int main(void) {
	cin >> N;
	if (N < DIGITS) cout << 0;
	else {
		init();
		long long sum = 0;

		for (int i = 2; i < N; i += 1) {
			copy_and_clear();
			for (int j = 0; j < DIGITS - 1; j += 1) {
				for (int k = 0; k < 1 << DIGITS; k += 1) {
					dp[j][k | MASK(j)] += buf[j + 1][k];
					dp[j][k | MASK(j)] %= M;
				}
			}
			for (int j = 1; j < DIGITS; j += 1) {
				for (int k = 0; k < 1 << DIGITS; k += 1) {
					dp[j][k | MASK(j)] += buf[j - 1][k];
					dp[j][k | MASK(j)] %= M;
				}
			}
		}

		cout << get_ans();
	}
	return 0;
}
