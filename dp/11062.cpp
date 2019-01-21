//https://www.acmicpc.net/problem/11062
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX_N 1000
using namespace std;

int N;
int card[MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1][2] = { 0, };
vector<int> answers;

void init() {
	cin >> N;
	memset(card, 0, sizeof card);
	for (int i = 1; i <= N; i += 1)
		cin >> card[i];
	memset(dp, 0, sizeof dp);
}

void solve() {
	init();

	int ans = 0;
	if (N == 1) ans = card[1];
	else if (N == 2) ans = max(card[1], card[2]);
	else {
		for (int j = 1; j <= N - 1; j++) {
			dp[1][j][0] = max(card[j], card[j + 1]);
			dp[1][j][1] = min(card[j], card[j + 1]);
		}

		for (int i = 2; i < N; i++) {
			for (int j = 1; j <= N - i; j++) {
				int comp1 = dp[i - 1][j][1] + card[j + i];
				int comp2 = dp[i - 1][j + 1][1] + card[j];

				if (comp1 >= comp2) {
					dp[i][j][0] = comp1;
					dp[i][j][1] = dp[i - 1][j][0];
				}
				else {
					dp[i][j][0] = comp2;
					dp[i][j][1] = dp[i - 1][j + 1][0];
				}
			}
		}

		ans = dp[N-1][1][0];
	}
	
	answers.push_back(ans);
}

int main(void) {
	int case_cnt = 0; cin >> case_cnt;
	for (int i = 0; i < case_cnt; i++)
		solve();
	for (int ans : answers)
		cout << ans << '\n';
	return 0;
}
