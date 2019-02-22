#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX_N 5001
#define MOD 1000000
#define endl '\n'
using namespace std;

string code;
int dp[MAX_N] = {0,};

bool is_alpha(char first) { return first != '0'; }
bool is_alpha2(char first, char second) { return first != '0' && (first - '0') * 10 + (second - '0') <= 26; }
int sum(int a, int b) { return (a%MOD+b%MOD)%MOD; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> code;

  /* init */
  dp[0] = is_alpha(code[0]) ? 1 : 0;
  if(code.size() == 1)
    cout << dp[0];
  else {
    dp[1] = (is_alpha(code[1]) ? 1 : 0) + (is_alpha2(code[0], code[1]) ? 1 : 0);
    /* fill */
    for(int i = 2 ; i < code.size() ; i++) {
      dp[i] = sum(dp[i], is_alpha(code[i]) ? dp[i-1] : 0);
      dp[i] = sum(dp[i], is_alpha2(code[i-1], code[i]) ? dp[i-2] : 0);
    }
    cout << dp[code.size() - 1];
  }
  return 0;
}
