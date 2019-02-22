#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define MAX_N 101
#define INT_MIN -1000000000
using namespace std;


int n,m;
int buf[MAX_N] = {0,};
int dp[MAX_N][MAX_N/2][2] = {0,};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
    cin >> buf[i];

  /* init */
  for(int i = 0 ; i < n ; i++)
    for(int j = 1 ; j <= m ; j++)
      dp[i][j][0] = dp[i][j][1] = INT_MIN;
  dp[0][1][1] = buf[0];
  
  /* fill */
  for(int i = 1 ; i < n ; i++) {
    for(int j = 1 ; j <= m ; j++) {
      dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
      if(dp[i-1][j][1] != INT_MIN) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + buf[i]);
      if(j != 1 && dp[i-1][j-1][0] != INT_MIN) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0] + buf[i]);
      if(j == 1) dp[i][1][1] = max(dp[i][1][1], buf[i]);
    }
  }
  /* ans */
  cout << max(dp[n-1][m][0], dp[n-1][m][1]);
  return 0;
}
