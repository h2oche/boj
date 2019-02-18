#include <iostream>
#include <algorithm>
#define MAX_N 1001
using namespace std;

int buf[MAX_N] = {0,};
int dp[MAX_N] = {0,};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> buf[i];

	dp[1] = buf[1];
	for(int i = 2 ; i <= n ; i++) {
		int max_val = buf[i];
		for(int j = 1 ; j < i ; j ++)
			max_val = max(max_val, dp[i-j]+buf[j]);
		dp[i] = max_val;
	}

	cout << dp[n];

	return 0;
}