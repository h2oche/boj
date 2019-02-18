#include <iostream>
#include <algorithm>
#define MAX_N 1001
#define M 10007
using namespace std;

int sum(int a, int b) {
  return (a%M+b%M)%M;
}

int buf[MAX_N] = {0,};
int dp[MAX_N][3] = {0,};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	for(int i = 3 ; i < MAX_N; i++) {
    dp[i][0] = sum(sum(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
    dp[i][1] = sum(sum(dp[i-2][0], dp[i-2][1]), dp[i-2][2]);
		dp[i][2] = dp[i][1];
  }

	int n; cin >> n;
	cout << sum(sum(dp[n][0], dp[n][1]), dp[n][2]);
	return 0;
}