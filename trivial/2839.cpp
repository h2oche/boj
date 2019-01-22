#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int dp[5001] = {0,};
int get_dp(int i) {
  if(dp[i] == 0 || dp[i] == -1)
    return INT_MAX;
  return dp[i];
}
void set_dp(int i, int val) {
  dp[i] = val == INT_MAX ? -1 : (val + 1);
}
int main(void)
{
  int n; cin >> n;
  dp[3] = 1, dp[5] = 1;
  if(n <= 5)
    cout << (dp[n] == 0 ? -1 : 1);
  else {
    for(int i = 6 ; i <= n ; i ++)
      set_dp(i, min(get_dp(i-3), get_dp(i-5)));
    cout << dp[n];
  }

  return 0;
}