//https://www.acmicpc.net/problem/9252
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#define MAX 1000
using namespace std;
pair<int,string> dp[MAX][MAX];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b; cin >> a >> b;

	/* init */
	dp[0][0] = a[0] == b[0] ? make_pair(1, a.substr(0, 1)) : make_pair(0, "");
	for (int i = 1; i < a.size(); i++)
		dp[0][i] = a[i] == b[0] ? make_pair(1, b.substr(0, 1)) : dp[0][i - 1];
	for (int i = 1; i < b.size(); i++)
		dp[i][0] = a[0] == b[i] ? make_pair(1, a.substr(0, 1)) : dp[i - 1][0];

	/* fill table */
	for (int i = 1; i < b.size(); i++) {
		for (int j = 1; j < a.size(); j++) {
			if (b[i] == a[j])
				dp[i][j] = make_pair(dp[i - 1][j - 1].first + 1, dp[i - 1][j - 1].second + a.substr(j, 1));
			else 
				dp[i][j] = dp[i - 1][j].first > dp[i][j - 1].first ? dp[i - 1][j] : dp[i][j - 1];
		}
	}

	auto ans = dp[b.size() - 1][a.size() - 1];
	cout << ans.first << '\n';
	cout << ans.second;

	return 0;
}
