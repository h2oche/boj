#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define endl '\n'
#define MAX_N 1001
using namespace std;
typedef pair<int, int> pii;

int n,m;
int buf[MAX_N][MAX_N] = {0,};
int dp[MAX_N][MAX_N] = {0,};
vector<pii> dirs = {{1,0},{0,1},{1,1}};
bool check(int i, int j) {
  if(i < 0 || j < 0) return false;
  if(i >= n || j >= m) return false;
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for(int i = 0; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      cin >> buf[i][j];
    }
  }
  dp[0][0] = buf[0][0];
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ;j < m ; j++) {
      for(auto dir : dirs) {
        int new_i = i + dir.first;
        int new_j = j + dir.second;
        if(!check(new_i, new_j)) continue;
        dp[new_i][new_j] = max(dp[new_i][new_j], dp[i][j] + buf[new_i][new_j]);
      }
    }
  }
  cout << dp[n-1][m-1];
  return 0;
}
