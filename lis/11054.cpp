#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX_N 1000
using namespace std;

int dp[MAX_N] = { 0, };
int dp2[MAX_N] = { 0, };
int buf[MAX_N] = { 0, };

int main(void) {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf[i];
		dp2[i] = 1; dp[i] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		int max_val = 0;
		for (int j = i + 1; j < n; j++) {
			if (buf[i] > buf[j]) {
				max_val = max(max_val, dp[j]);
			}
		}
		dp[i] += max_val;
	}

	for (int i = 0; i < n; i++) {
		int max_val = 0;
		for (int j = 0; j < i; j++) {
			if (buf[j] < buf[i]) {
				max_val = max(max_val, dp2[j]);
			}
		}
		dp2[i] += max_val;
	}

	int max_val = 0;
	for (int i = 0; i < n; i++) {
		max_val = max(max_val, dp[i] + dp2[i] - 1);
	}

	cout << max_val;

	return 0;
}
