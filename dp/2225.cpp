#include <iostream>
#include <algorithm>
#define MAX_N 201
#define MOD 1000000000
using namespace std;

int sum(int a, int b) {
  return (a%MOD+b%MOD)%MOD;
}
int mul(int a, int b) {
  return ((long long)(a%MOD)*(b%MOD))%MOD;
}

int n,k;
int dp[MAX_N][MAX_N] = {0,};
int bi[MAX_N][MAX_N] = {0,};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;

  /* binomial */
  for(int i = 1 ; i <= k ; i++) {
    bi[i][0] = 1;
    bi[i][1] = i;
    bi[i][i] = 1;
  }

  for(int i = 2 ; i <= k ; i++)
    for(int j = 2 ; j <= k ; j++)
      bi[i][j] = sum(bi[i-1][j-1], bi[i-1][j]);
  
  /* init */
  for(int i = 1 ; i <= n ; i++) {
    dp[i][1] = i;
    dp[i][i] = 1;
  }

  for(int i = 2 ; i <= n ; i++) {
    for(int j = 2; j <= k && j <= i ; j++) {
      dp[i][j] = dp[i-1][j-1];
      dp[i][j] = sum(dp[i][j], dp[i-1][j]);
    }
  }

  int ans = 0;
  for(int j = 1; j <= k ; j++)
    ans = sum(ans, mul( sum(dp[n][j], MOD - dp[n-1][j]), bi[k][j]));
  cout << ans;
  
  return 0;
}
