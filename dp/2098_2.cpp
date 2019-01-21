#include <iostream>
#include <cstdint>
#include <climits>
#include <algorithm>
#define MAX_N 16

#define MASK(n) (1 << (n))
#define MASK_ALL (MASK(N) - 1)
#define MASK_EX(n) (~(MASK(n))) & MASK_ALL
using namespace std;

int N;
int ans = INT_MAX;
int W[MAX_N][MAX_N] = { 0, };
/* dp[j][mask] : 0 -> j 까지 mask에 포함된 점들을 통해서 가는 경로 중, 최솟값 */
int dp[MAX_N][MASK(MAX_N)] = { 0, };

void init() {
	for (int j = 0; j < N; j++) {
		if (W[0][j] == 0) dp[j][MASK(j) | MASK(0)] = -1;
		else dp[j][MASK(j) | MASK(0)] = W[0][j];
	}
}

int get_shortest(int j, uint16_t mask) {
	/*
	base case
	1) j가 경로에 없는 경우 -> -1로 기록하고 return
	2) 이미 계산한 경로일 경우 -> 바로 return
	*/
	if ((MASK(j) & mask) == 0)
		return dp[j][mask] = -1;
	else if (dp[j][mask] != 0)
		return dp[j][mask];

	int ans = INT_MAX;

	/* 0 -> k -> j로 가는 경로를 계산 */
	for (int k = 1; k < N; k += 1) {
		/*
		1) j == k 일 경우
		2) k가 경로에 없을 경우
		3) k -> j로 가는 길이 없을 경우
		-> 계산하지 않음
		4) 그 외의 경우 -> dp[k][mask & MASK_EX(j)] 를 구해서 dp에 기록함
		*/
		if (j == k || mask & MASK(k) == 0 || W[k][j] == 0) continue;
		int temp_s = get_shortest(k, mask & MASK_EX(j));
		if (temp_s == -1) continue;
		ans = min(ans, temp_s + W[k][j]);
	}

	return dp[j][mask] = (ans == INT_MAX ? -1 : ans);
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
			if (W[j][0] == 0 || (s = get_shortest(j, MASK_ALL)) == -1) continue;
			ans = min(ans, s + W[j][0]);
		}
	}
	cout << ans;
	return 0;
}
