#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define endl '\n'
#define MOD 100000
#define MAX_N 210
using namespace std;
typedef long long ll;

ll dp[MAX_N][MAX_N];
bool overflowed[MAX_N][MAX_N] = {false,};
int n;
string str;
string pattern[10] = {"()", "(?", "?)", "[]", "[?", "?]", "{}", "{?", "?}", "??"};
int factor(string& str) {return pattern[9].compare(str) == 0 ? 3 : 1;}

ll count(int start, int end) {
  ll& ret = dp[start][end];
  if(ret != -1) return ret;
  ret = 0;

  if(end-start < 2) return ret = 0;
  else if(end-start == 2) {
    string temp = str.substr(start,2);
    return ret = 
    any_of(pattern, pattern+10, [&temp](string& p) -> bool {
      return temp.compare(p) == 0;
    }) ? 1 * factor(temp) : 0;
  }

  string temp = string(2, str[start]);
  for(int i = start+1; i < end ; i++) {
    temp[1] = str[i];
    if(any_of(pattern, pattern+10, [&temp](string& p) -> bool {
      return temp.compare(p) == 0;
    })) {
      ll inner = start+1 == i ? 1 : count(start+1, i);
      ll outer = i+1 == end ? 1 : count(i+1, end);
      ll res = factor(temp) * inner * outer;
      if(res > 0 && (overflowed[start+1][i] || overflowed[i+1][end])) overflowed[start][end] = true;
      ret += factor(temp) * inner * outer;
      if(ret >= MOD) overflowed[start][end] = true;
      ret %= MOD;
    }
  }
  return ret;
}

int main()
{
  memset(dp, -1, sizeof dp);
  cin >> n >> str;
  ll res = count(0, n);
  printf(overflowed[0][n] ? "%05lld" : "%lld", res);
  return 0;
}
