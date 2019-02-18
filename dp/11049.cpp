#include <iostream>
#include <utility>
#include <algorithm>
#define MAX_N 501
using namespace std;

pair<int, int> matrix[MAX_N];
int dp[MAX_N][MAX_N] = {0,};
int n;

int get_min(int a, int b) {
	if(a == 0) return b;
	else return min(a, b);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1 ; i <= n; i++)
		cin >> matrix[i].first >> matrix[i].second;

	//init
	for(int i = 1; i < n ; i++)
		dp[i][i+1] = matrix[i].first * matrix[i].second * matrix[i+1].second;

	//fill dp
	for(int l = 2; l < n ; l++) {
		for(int i = 1 ; i + l <= n ; i++) {
			for(int k = i; k <= i + l ; k++) {
				int f = matrix[i].first * matrix[k].second * matrix[i+l].second;
				dp[i][i+l] = get_min(dp[i][i+l], dp[i][k] + dp[k+1][i+l] + f);
			}
		}
	}

	cout << dp[1][n];
	return 0;
}