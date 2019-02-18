#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>
#include <utility>
#define MAX_N 1001
using namespace std;

int N, W;
int dp[MAX_N][MAX_N] = {0,};
pair<int, int> record[MAX_N][MAX_N];
pair<int, int> buf[MAX_N];
pair<int, int> a_start, b_start;

int get_dist(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int get_dist_idx(int a, int b) {
  auto _a = buf[a], _b = buf[b];
  if(a == 0) _a = a_start;
  if(b == 0) _b = b_start;
  return get_dist(_a, _b);
}

int get_min(int a, int b) {
  if(a != 0) return min(a, b);
  return b;
}

void update_and_record(int a, int b, int prev_a, int prev_b) {
  int test_val = dp[prev_a][prev_b];
  test_val += prev_a == a ? 0 : get_dist_idx(prev_a, a);
  test_val += prev_b == b ? 0 : get_dist_idx(b, prev_b);
  if(dp[a][b] == 0 || dp[a][b] > test_val) {
    dp[a][b] = test_val;
    record[a][b] = make_pair(prev_a, prev_b);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> W;
  for(int i = 1 ; i <= W ; i++)
    cin >> buf[i].first >> buf[i].second;

  a_start = make_pair(1,1);
  b_start = make_pair(N,N);
  dp[0][1] = get_dist(b_start, buf[1]);
  dp[1][0] = get_dist(a_start, buf[1]);

  for(int i = 2 ; i <= W ; i ++) {
    for(int k = 0 ; k < i - 1 ; k ++) {
      // dp[k][i] = get_min(dp[k][i], dp[k][i-1] + get_dist_idx(i, i-1));
      // dp[i][k] = get_min(dp[i][k], dp[i-1][k] + get_dist_idx(i-1, i));
      // dp[i-1][i] = get_min(dp[i-1][i], dp[i-1][k] + get_dist_idx(i, k));
      // dp[i][i-1] = get_min(dp[i][i-1], dp[k][i-1] + get_dist_idx(k, i));
      update_and_record(k, i, k, i -1);
      update_and_record(i, k, i-1, k);
      update_and_record(i-1, i, i-1, k);
      update_and_record(i, i-1, k, i-1);
    }
  }
  int ans = INT_MAX;
  pair<int, int> rec;
  pair<int, int> zero = make_pair(0,0);
  for(int i = 0 ; i < W; i ++) {
    if(ans > dp[W][i]) {
      ans = dp[W][i];
      rec = make_pair(W, i);
    }
    if(ans > dp[i][W]) {
      ans = dp[i][W];
      rec = make_pair(i, W);
    }
  }
  cout << ans << '\n';

  stack<int> results;
  while(rec != zero) {
    results.push(rec.first == W ? 1 : 2);
    rec = record[rec.first][rec.second];
    W--;
  }

  while(!results.empty()) {
    cout << results.top() << '\n';
    results.pop();
  }

  return 0;
}