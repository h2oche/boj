//https://www.acmicpc.net/problem/2293
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#define N 100
#define M 10000
using namespace std;

int n, k;
vector<int> coins;
int dp[M + 1] = { 0, };

int get_dp(int i) {
	if (i >= 0 && i <= k)
		return dp[i];
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i += 1) {
		int coin; cin >> coin;
		coins.push_back(coin);
	}
	sort(coins.begin(), coins.end());

	for (int i = 0; i < n; i += 1) {
		for (int j = k; j >= 1 ; j -= 1) {
			for (int k = 1; j - k * coins[i] >= 0; k += 1)
				dp[j] += get_dp(j - k * coins[i]);
			if (j % coins[i] == 0) dp[j]++;
		}
	}

	cout << dp[k];

	return 0;
}