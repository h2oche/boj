#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define MAX_N 100001
using namespace std;

int n;
int buf[2][MAX_N] = {0,};
struct dp_element {
  int a, b, c;
  dp_element():a(0),b(0),c(0){}
  dp_element(int a, int b, int c):a(a), b(b),c(c){}
};
dp_element dp[MAX_N];

void init() {
  memset(buf, 0, sizeof buf);
  memset(dp, 0, sizeof dp);
  cin >> n;
  for(int i = 0 ; i < 2 ; i++)
    for(int j = 1 ; j <= n ; j++)
      cin >> buf[i][j];
}

void solve() {
  init();
  //init
  dp[1] = {0, buf[0][1], buf[1][1]};
  //fill
  for(int i = 2; i <= n ; i++) {
    dp[i].a = max(max(dp[i-1].a, dp[i-1].b), dp[i-1].c);
    dp[i].b = max(dp[i-1].a, dp[i-1].c) + buf[0][i];
    dp[i].c = max(dp[i-1].a, dp[i-1].b) + buf[1][i];
  }
  int ans = max(max(dp[n].a, dp[n].b), dp[n].c);
  cout << ans << endl;
}

int tc;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> tc;
  for(int i = 0 ; i < tc ; i++)
    solve();
  return 0;
}
