#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 31
using namespace std;

int n;
int dp[MAX_N] = {0,};
int dp_sum[MAX_N] = {0,};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

  cin >> n;
  long long ans = 0;
  if(n % 2 == 1) ans = 0;
  else {
    n = n / 2;
    dp[1] = 3; dp_sum[1] = 3;
    for(int i = 2 ; i < MAX_N ; i++) {
      dp[i] = 2 * dp_sum[i-1] + dp[i-1] + 2;
      dp_sum[i] = dp_sum[i-1] + dp[i];
    }
    ans = dp[n];
  }
	cout << ans;
	return 0;
}