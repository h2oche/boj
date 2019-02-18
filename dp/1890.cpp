#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 101
using namespace std;

int n,m;
int map[MAX_N][MAX_N] = {0,};
long long dp[MAX_N][MAX_N] = {0,};

bool check(int i, int j) {
  return (i>=0 && i<n) && (j>=0 && j<n);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < n ; j++)
      cin >> map[i][j];

  //init
  if(check(0, map[0][0])) dp[0][map[0][0]] = 1;
  if(check(map[0][0], 0)) dp[map[0][0]][0] = 1;

  //fill table
  for(int s = 1; s < 2*n - 2 ; s++) {
    for(int i = s; i >=0 ; i--) {
      int j = s - i;
      if(check(i, j) && dp[i][j] > 0) {
        int v = map[i][j];
        if(v == 0) continue;
        if(check(i+v, j)) dp[i+v][j] += dp[i][j];
        if(check(i, j+v)) dp[i][j+v] += dp[i][j];
      }
    }
  }

  cout << dp[n-1][n-1];
  
  return 0;
}
