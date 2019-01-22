//https://www.acmicpc.net/problem/11066
#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
#define MAX_K 500
using namespace std;

int dp[MAX_K + 1][MAX_K + 1][2];
int k;
vector<int> results;

void init() {
	memset(dp, 0, sizeof dp);
	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> dp[1][i][0];
}
int get_real(int i, int j) {
	return dp[i][j][0] + dp[i][j][1];
}
void solve() {
	init();
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= k - i + 1; j++) {
			int min_val = INT_MAX;
			int wl = 0;
			for (int m = 1; m < i; m++) {
				int candid = get_real(m, j) + get_real(i - m, j + m);
				if (min_val > candid)
					min_val = candid, wl = dp[m][j][0] + dp[i - m][j + m][0];
			}
			dp[i][j][0] = wl;
			dp[i][j][1] = min_val;
		}
	}
	results.push_back(dp[k][1][1]);
}
void print_ans() {
	for (auto res : results)
		cout << res << '\n';
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++)
		solve();
	print_ans();
	return 0;
}
