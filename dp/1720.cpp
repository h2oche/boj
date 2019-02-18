#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 31
using namespace std;

struct dp_element {
  int sym, total;
  dp_element(): sym(0),total(0){}
  dp_element(int sym, int total):sym(sym), total(total){}
};

int n;
dp_element dp[MAX_N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  dp[1] = dp_element(1, 1);
  dp[2] = dp_element(3, 3);
  dp[3] = dp_element(1, 5);
  dp[4] = dp_element(5, 11);
  for(int i = 5 ; i <= 30; i++)
    dp[i] = dp_element(dp[i-2].sym + dp[i-4].sym * 2, dp[i-1].total + dp[i-2].total * 2);

  cin >> n;
  cout << dp[n].sym + (dp[n].total - dp[n].sym) / 2;
  return 0;
}
