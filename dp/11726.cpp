#include <iostream>
#define M 10007
using namespace std;

int dp[1010][2] = {0,};

int sum(int a, int b) {
  return (a%M+b%M)%M;
}

int main(void) {
  dp[1][0] = 1;
  dp[2][0] = 1;
  dp[2][1] = 1;
  for(int i = 3 ; i <= 1000; i++) {
    dp[i][0] = sum(dp[i-1][0], dp[i-1][1]);
    dp[i][1] = sum(dp[i-2][0], dp[i-2][1]);
  }
  int n; cin >> n;
  cout << sum(dp[n][0], dp[n][1]);
  return 0;
}