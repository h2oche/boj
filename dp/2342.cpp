#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX_N 100010
using namespace std;

int buf[MAX_N] = {0,};
int dp[MAX_N][5][5] = {0,};
int cost[5][5] = {
  {0,2,2,2,2},
  {0,1,3,4,3},
  {0,3,1,3,4},
  {0,4,3,1,3},
  {0,3,4,3,1}
};

int get_min(int a, int b) {
  if(a != 0) return min(a, b);
  else return b;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 0;
  for(n = 0 ; ; n++) {
    cin >> buf[n];
    if(buf[n] == 0) break;
  }

  dp[0][buf[0]][0] = 2;
  dp[0][0][buf[0]] = 2;
  
  for(int i = 1 ; buf[i] != 0; i++) {
    for(int j = 0 ; j < 5 ; j ++) {
      for(int k = 0 ; k < 5 ; k++) {
        if(dp[i-1][j][k] == 0) continue;
        if(j == buf[i] || k == buf[i]) dp[i][j][k] = get_min(dp[i][j][k], dp[i-1][j][k] + 1);
        else {
          dp[i][j][buf[i]] = get_min(dp[i][j][buf[i]], dp[i-1][j][k] + cost[k][buf[i]]);
          dp[i][buf[i]][k] = get_min(dp[i][buf[i]][k], dp[i-1][j][k] + cost[j][buf[i]]);
        }
      }
    }
  }

  int ans = INT_MAX;
  for(int i = 0 ; i < 5 ; i++)
    for(int j = 0 ; j < 5 ; j++)
      ans = min(ans, (dp[n-1][i][j] == 0 ? INT_MAX : dp[n-1][i][j]));

  cout << (ans == INT_MAX ? 0 : ans);
  return 0;
}