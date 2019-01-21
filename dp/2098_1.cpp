#include <iostream>
#include <cstdint>
#include <climits>
#include <algorithm>
#define MAX_N 16
#define MAX_VAL 1000000

#define MASK(n) (1 << (n))
#define MASK_ALL (MASK(N) - 1)
#define MASK_EX(n) (~(MASK(n))) & MASK_ALL
using namespace std;

int N;
int ans = MAX_N * MAX_VAL + 1;
int W[MAX_N][MAX_N] = { 0, };
int dp[MAX_N][MAX_N][MASK(MAX_N)] = { 0, };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			else if(W[i][j] == 0) dp[i][j][MASK(i) | MASK(j)] = -1;
			else dp[i][j][MASK(i) | MASK(j)] = W[i][j];
		}
	}
}

int get_shortest(int i, int j, uint16_t mask) {
	if ( (MASK(i) & mask) == 0 || (MASK(j) & mask) == 0)
		return dp[i][j][mask] = -1;
	else if (dp[i][j][mask] != 0)
		return dp[i][j][mask];

	int ans = INT_MAX;

	for (int k = 0; k < N; k += 1) {
		if (i == j || j == k || k == i || mask & MASK(k) == 0 || W[k][j] == 0) continue;
		int new_mask = mask & MASK_EX(j);
		int temp_s = get_shortest(i, k, new_mask);
		if (temp_s == -1) continue;
		ans = min(ans, temp_s + W[k][j]);
	}

	return dp[i][j][mask] = (ans == INT_MAX ? -1 : ans);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i += 1)
		for (int j = 0; j < N; j += 1)
			cin >> W[i][j];

	if (N == 2) ans = W[0][1] + W[1][0];
	else {
		//init dp table
		init();

		//calculate
		for (int j = 1; j < N; j++) {
			int s = 0;
			if (W[j][0] == 0 || (s = get_shortest(0, j, MASK_ALL)) == -1) continue;
			ans = min(ans, s + W[j][0]);
		}
	}
	cout << ans;
	return 0;
}
