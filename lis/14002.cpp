#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#define MAX_N 1000
using namespace std;

pair<int, int> dp[MAX_N];
int buf[MAX_N] = { 0, };

int main(void) {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf[i];
		dp[i] = make_pair(1, i);
	}

	for (int i = n - 1; i >= 0; i--) {
		int max_val = 0; int temp_j = i;
		for (int j = i + 1; j < n; j++) {
			if (buf[i] < buf[j] && max_val < dp[j].first) {
				max_val = dp[j].first;
				temp_j = j;
			}
		}
		dp[i] = make_pair(dp[i].first + max_val, temp_j);
	}

	int max_val = 0; int temp_i;
	for (int i = 0; i < n; i++) {
		if (max_val < dp[i].first) {
			max_val = dp[i].first;
			temp_i = i;
		}
	}

	cout << max_val << '\n';

	do {
		cout << buf[temp_i] << ' ';
		if (temp_i == dp[temp_i].second) break;
		temp_i = dp[temp_i].second;
	} while (true);

	return 0;
}
