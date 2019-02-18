#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#define endl '\n'
#define MAX_N 2501
using namespace std;

string str;
bool p_dp[MAX_N][MAX_N] = {false,};
int dp[MAX_N] = {0,};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> str;

  for(int i = 0; i < str.size() - 1; i++) {
    p_dp[i][i] = true;
    p_dp[i][i+1] = str[i] == str[i+1];
  }
  p_dp[str.size()-1][str.size()-1] = true;

  for(int l = 3; l <= str.size() ; l++) {
    for(int start = 0; start <= str.size() - l; start++) {
      int end = start + l - 1;
      p_dp[start][end] = str[start] == str[end] ? p_dp[start+1][end-1] : false;
    }
  }
  dp[0] = 1;
  for(int i = 1; i < str.size(); i++) {
    if(p_dp[0][i]) {
      dp[i] = 1;
      continue;
    }
    int ans = INT_MAX;
    for(int j = i; j > 0 ; j--)
      if(p_dp[j][i])
        ans = min(ans, dp[j-1] + 1);
    dp[i] = ans;
  }
  
  cout << dp[str.size()-1];
  return 0;
}
