#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX_N 1000
using namespace std;

int dp[MAX_N] = { 0, };
int buf[MAX_N] = { 0, };

int main(void) {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf[i];
		dp[i] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		int max_val = 0;
		for (int j = i + 1; j < n; j++) {
			if (buf[i] < buf[j]) {
				max_val = max(max_val, dp[j]);
			}
		}
		dp[i] += max_val;
	}

	cout << *max_element(dp, dp + n);

	return 0;
}
