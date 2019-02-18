#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX_N 4000
#define endl '\n'
using namespace std;

string n,m;
int dp[MAX_N][MAX_N] = {0,};
int get_dp(int i, int j) {
  if(i < 0 || j < 0) return 0;
  else return dp[i][j];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  int ans = 0;
  for(int i = 0 ; i < n.size() ; i++) {
    for(int j = 0 ; j < m.size() ; j++) {
      if(n[i] == m[j]) {
        dp[i][j] = get_dp(i-1, j-1) + 1;
        ans = max(dp[i][j], ans);
      }
    }
  }
  cout << ans;
  return 0;
}
