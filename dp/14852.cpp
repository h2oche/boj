#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define MOD 1000000007
#define MAX_N 1000001
using namespace std;

int sum(int a, int b) {
  return (a%MOD+b%MOD)%MOD;
}
int mul(int a, int b) {
  return ((long long)(a%MOD)*(b%MOD))%MOD;
}

int cofac(int n) {
	if(n == 1) return 2;
	else if(n == 2) return 4;
	else return 2;
}

int n;
int dp[MAX_N] = {0,};
int dp_sum[MAX_N] = {0,};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
  dp[1] = 2, dp_sum[1] = 2;
  dp[2] = 7, dp_sum[2] = 9;
  for(int i = 3 ; i < MAX_N ; i++) {
    dp[i] = sum(sum(mul(2, dp_sum[i-1]), dp[i-2]), 2);
    dp_sum[i] = sum(dp_sum[i-1], dp[i]);
  }

  cin >> n;
  cout << dp[n];
	return 0;
}