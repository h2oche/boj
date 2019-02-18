#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

pair<int, int> dp[41];
pair<int, int> zero;

pair<int, int> get_dp(int n) {
  if(dp[n] != zero ) return dp[n];
  auto res1 = get_dp(n-1);
  auto res2 = get_dp(n-2);
  return dp[n] = make_pair(res1.first + res2.first, res1.second + res2.second);
}

pair<int, int> solve() {
  int n; cin >> n;
  return get_dp(n);
}

vector<pair<int, int>> results;
int main(void) {
  memset(dp, 0, sizeof dp);
  zero = make_pair(0, 0);
  dp[0] = make_pair(1, 0);
  dp[1] = make_pair(0, 1);
  dp[2] = make_pair(1, 1);

  int tc; cin >> tc;
  for(int i = 0 ; i < tc; i++)
    results.push_back(solve());
  for(auto p : results)
    cout << p.first << ' ' << p.second << '\n';
  return 0;
}