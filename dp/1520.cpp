//https://www.acmicpc.net/problem/1520
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<int>> dp;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int get_map(int x, int y) {
	if (!(y > 0 && y <= n && x > 0 && x <= m))
		return 0;
	return map[y][x];
}

int get_dp(int x, int y) {
	if (!(y > 0 && y <= n && x > 0 && x <= m))
		return 0;
	else if (x == 1 && y == 1) return 1;
	else if (dp[y][x] != -1) return dp[y][x];

	int cum = 0;
	for (int i = 0; i < 4; i += 1) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if(map[y][x] < get_map(new_x, new_y))
			cum += get_dp(new_x, new_y);
	}
	
	return dp[y][x] = cum;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	/* input */
	cin >> n >> m;
	map = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MAX));
	dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
	for (int i = 1; i <= n; i += 1)
		for (int j = 1; j <= m; j += 1)
			cin >> map[i][j];

	cout << get_dp(m,n);

	return 0;
}