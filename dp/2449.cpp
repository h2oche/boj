#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#define MAX_N 200
#define MAX_K 21
using namespace std;

int n, k;
int buf[MAX_N] = {0,};
pair<int, set<int>> dp[MAX_N][MAX_N+1];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++) cin >> buf[i];
  for(int i = 0 ; i < n ; i++)
    dp[i][1] = make_pair(0, set<int>({buf[i]}));

  for(int l = 2 ; l <= n ; l++) {
    for(int i = 0 ; i < n - l + 1  ; i ++) {
      int min_val = 1000;
      set<int> min_set;

      for(int j = 1 ; j < l ; j ++) {
        vector<int> v(20);
        auto it = set_intersection(dp[i][j].second.begin(), dp[i][j].second.end(),
                                  dp[i+j][l-j].second.begin(), dp[i+j][l-j].second.end(),
                                  v.begin());
        v.resize(it - v.begin());
        int temp = dp[i][j].first + dp[i+j][l-j].first;
        if(v.size() == 0) {
          temp++;
          if(temp < min_val) {
            min_val = temp;
            min_set = dp[i][j].second;
            min_set.insert(dp[i+j][l-j].second.begin(), dp[i+j][l-j].second.end());
          }
        } else {
          if(temp < min_val) {
            min_val = temp;
            min_set.clear();
            min_set.insert(v.begin(), v.end());
          }
        }
      }

      dp[i][l] = make_pair(min_val, min_set);
    }
  }

  cout << dp[0][n].first;

  return 0;
}