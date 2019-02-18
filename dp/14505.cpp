#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX_N 31
#define endl '\n'
using namespace std;

string str;
int dp[MAX_N][MAX_N] = {0,};
int find(int start, int end) {
  if(dp[start][end] != -1) return dp[start][end];
  if(start == end) return dp[start][end] = 1;
  else if(start + 1 == end) {
    if(str[start] == str[end]) return dp[start][end] = 3;
    else return dp[start][end] = 2;
  }

  int ret = 0;
  ret += find(start+1, end);
  ret += find(start, end-1);
  ret -= find(start+1,end-1);
  if(str[start] == str[end])
    ret += find(start+1, end-1) + 1;
  
  return dp[start][end] = ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> str;
  memset(dp, -1, sizeof dp);
  cout << find(0, str.size()-1);
  return 0;
}

