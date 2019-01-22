//https://www.acmicpc.net/problem/9251
#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000
using namespace std;
int dp[MAX][MAX] = { 0, };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b; cin >> a >> b;
	/* init */
	dp[0][0] = a[0] == b[0] ? 1 : 0;
	for (int i = 1; i < a.size(); i++)
		dp[0][i] = a[i] == b[0] ? 1 : dp[0][i-1];
	for (int i = 1; i < b.size(); i++)
		dp[i][0] = a[0] == b[i] ? 1 : dp[i - 1][0];

	/* fill table */
	for (int i = 1; i < b.size(); i++) {
		for (int j = 1; j < a.size(); j++) {
			int m1 = max(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] = b[i] == a[j] ? dp[i-1][j-1] + 1 : m1;
		}
	}

	cout << dp[b.size()-1][a.size()-1];

	return 0;
}
