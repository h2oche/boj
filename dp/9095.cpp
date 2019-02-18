#include <iostream>
#include <algorithm>
using namespace std;
int dp[11][4] = {0,};
void solve() {
	int n; cin >> n;
	cout << dp[n][1] + dp[n][2] + dp[n][3] << endl;
}
int main(void){
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 2;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for(int i = 4 ; i < 11 ; i++) {
		dp[i][1] = dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
		dp[i][2] = dp[i-2][1] + dp[i-2][2] + dp[i-2][3];
		dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
 	}
	int tc; cin >> tc;
	for(int i = 0 ; i < tc ; i++)
		solve();
	return 0;
}