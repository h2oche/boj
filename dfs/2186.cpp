#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define endl '\n'
#define MAX_N 101
#define MAX_LEN 81
using namespace std;
typedef pair<int, int> pii;

int n,m,k;
char buf[MAX_N][MAX_N] = {0,};
int dp[MAX_N][MAX_N][MAX_LEN] = {0,};
string str = {0,};
vector<pii> dir;
int find_cnt = 0;

bool check(int i, int j) {
  if(i < 0 || j < 0) return false;
  if(i >= n || j >= m) return false;
  return true;
}

int find(int i, int j, int a) {
  if(dp[i][j][a] != -1) return dp[i][j][a];
  if(a >= str.size()) return 0;
  if(buf[i][j] != str[a]) return 0;
  if(a == str.size() - 1) return 1;

  int ret = 0;
  for(auto _dir : dir) {
    int new_i = i + _dir.first;
    int new_j = j + _dir.second;
    if(!check(new_i, new_j)) continue;
    ret += find(new_i, new_j, a+1);
  }

  return dp[i][j][a] = ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for(int i = 0 ; i < n; i++)
    cin >> buf[i];
  cin >> str;

  for(int i = 1 ; i <= k ; i++) {
    dir.push_back(pii(i,0));
    dir.push_back(pii(-i,0));
    dir.push_back(pii(0,i));
    dir.push_back(pii(0,-i));
  }

  memset(dp, -1, sizeof dp);

  int ans = 0;
  for(int i = 0 ; i < n ; i++) {
    for(int j = 0 ; j < m ; j++) {
      ans += find(i, j, 0);
    }
  }
  cout << ans;
  
  return 0;
}
