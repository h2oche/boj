#include <iostream>
#include <algorithm>
#include <utility>
#define MAX_T 1001
#define MAX_W 31
using namespace std;

int dp[MAX_T][MAX_W] = {0,};
int T, W;

int get_dp(int i, int j) {
	if(j < 0) return 0;
	else return dp[i][j];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T >> W;
	for(int i = 0 ; i < T ; i ++) {
		int buf; cin >> buf;

		//init
		if(i == 0) {
			for(int j = 0 ; j <= W ; j++) {
				if(buf == 1) dp[0][j] = j % 2 == 0 ? 1 : 0;
				else dp[0][j] = j % 2 == 1 ? 1 : 0;
			}
			continue;
		}

		for(int j = 0 ; j <= W ; j++) {
			if(buf == 1) {
				if(j % 2 == 0) {
					dp[i][j] = max(dp[i][j], get_dp(i-1, j) + 1);
					dp[i][j] = max(dp[i][j], get_dp(i-1, j-1) + 1);
				} else {
					dp[i][j] = dp[i-1][j];
				}
			} else {
				if(j % 2 == 1) {
					dp[i][j] = max(dp[i][j], get_dp(i-1, j) + 1);
					dp[i][j] = max(dp[i][j], get_dp(i-1, j-1) + 1);
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}

	int ans = 0;
	for(int j = 0; j <= W ; j++)
		ans = max(ans, dp[T-1][j]);
	cout << ans;

	return 0;
}