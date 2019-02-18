#include <iostream>
#define MAX_N 101
#define MAX_M 21
using namespace std;

int n, s;
long long dp[MAX_N][MAX_M] = {0,};

bool check(int num) {
	return num>=0 && num<MAX_M;
}

int main(void) {
	cin >> n >> s; dp[1][s] = 1;
	for(int i = 2 ; i < n ; i++) {
		cin >> s;
		for(int j = 0 ; j < MAX_M ; j++) {
			if(dp[i-1][j] > 0) {
				if(check(j+s)) dp[i][j+s] += dp[i-1][j];
				if(check(j-s)) dp[i][j-s] += dp[i-1][j];
			}
		}
	}
	cin >> s;
	cout << dp[n-1][s];
	return 0;
}