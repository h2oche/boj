#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#define endl '\n'
#define MAX_N 2501
using namespace std;

string str;
int dp[MAX_N][MAX_N] = {0,};
int get_ans(int start, int end);

bool is_palindrome(int start, int end) {
  if(dp[start][end] != -1) return dp[start][end] == 1;
  if(start == end) return true;
  else if(start + 1 == end) return (dp[start][end] = (str[start] == str[end] ? 1 : 2)) == 1;
  else if(str[start] != str[end]) return false;
  else return (dp[start+1][end-1] = get_ans(start+1, end-1)) == 1;
}

int get_ans(int start, int end) {
  if(dp[start][end] != -1) return dp[start][end];
  if(start == end) return dp[start][end] = 1;
  if(start + 1 == end) {
    if(str[start] == str[end]) return dp[start][end] = 1;
    else return dp[start][end] = 2;
  }
  if(is_palindrome(start, end)) return dp[start][end] = 1;

  int ret = INT_MAX;
  for(int j = start; j < end ; j++)
    ret = min(ret, get_ans(start, j) + get_ans(j+1, end));

  return dp[start][end] = ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> str;
  memset(dp, -1, sizeof dp);
  cout << get_ans(0, str.size()-1);
  return 0;
}
