#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 1001
#define M 10007
using namespace std;

int n;
int dp[MAX_N][10] = {0,};
int sum(int a, int b) {
  return (a%M +b%M)%M;
}
int sum2(int i, int k) {
  int ret = 0;
  for(int j = 0 ; j <= k ; j++)
    ret = sum(ret, dp[i][j]);
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  for(int i = 0 ; i < 10 ; i++) dp[1][i] = 1;
  for(int i = 2 ; i <= n ; i++)
    for(int k = 0 ; k < 10; k ++)
      dp[i][k] = sum2(i-1, k);

  int ans = 0;
  for(int i = 0 ; i < 10 ; i++)
    ans = sum(ans, dp[n][i]);
  cout << ans;
  
  return 0;
}
