//https://www.acmicpc.net/problem/1005
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#define MAX_N 1000
#define MAK_K 100000
using namespace std;
int buildings[MAX_N + 1];
int dp[MAX_N + 1];
map<int, vector<int>> techs;
int n, k, target;


void init() {
	memset(dp, -1, sizeof dp);
	memset(buildings, 0, sizeof buildings);
	techs.clear();

	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i += 1)
		cin >> buildings[i];
	
	for (int i = 1; i <= k; i += 1) {
		int l, h; cin >> l >> h;
		techs[h].push_back(l);
	}

	cin >> target;
}

int get_cost(int i) {
	if (dp[i] != -1) return dp[i];
	if (techs[i].size() == 0) return dp[i] = buildings[i];

	vector<int> times = vector<int>(techs[i].size());
	transform(techs[i].begin(), techs[i].end(), times.begin(), [](int j) -> int {
		return get_cost(j);
	});
	return dp[i] = *max_element(times.begin(), times.end()) + buildings[i];
}

vector<int> results;
void solve() {
	init();

	results.push_back(get_cost(target));
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
