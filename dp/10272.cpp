#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
#define MAX_N 513
using namespace std;

struct coord{
  int x, y;
  coord() : x(0), y(0) {}
  long double get_dist(const coord& c) {
    return sqrtl(abs(x - c.x)*abs(x - c.x) + abs(y - c.y)*abs(y-c.y));
  }
};

int n;
vector<coord> buf;
long double dp[MAX_N][MAX_N] = {0,};

long double get_min(long double a, long double b) {
  if(a != 0) return min(a, b);
  return b;
}

long double get_dist(int a, int b) {
  return buf[a].get_dist(buf[b]);
}

void init() {
  scanf("%d\n",&n);
  buf.clear();
  buf = vector<coord>(n+1);
  for(int i = 1; i <= n ; i ++)
    scanf("%d %d\n", &buf[i].x, &buf[i].y);
  memset(dp, 0, sizeof dp);
  dp[1][1] = 2 * buf[1].get_dist(buf[n]);
}

long double solve() {
  init();
  if(n == 2) return dp[1][1];

  dp[2][1] = get_dist(1, 2) + get_dist(2, n) + get_dist(n ,1);
  dp[1][2] = get_dist(1, n) + get_dist(n, 2) + get_dist(2, 1);

  for(int i = 3 ; i < n ; i++) {
    for(int k = 1 ; k < i - 1 ; k++) {
      dp[i][k] = get_min(dp[i][k], dp[i-1][k] + get_dist(i-1,i) + get_dist(i, n) - get_dist(i-1,n));
      dp[k][i] = get_min(dp[k][i], dp[k][i-1] + get_dist(i-1,i) + get_dist(i, n) - get_dist(i-1,n));
      dp[i][i-1] = get_min(dp[i][i-1], dp[k][i-1] + get_dist(k, i) + get_dist(i, n) - get_dist(k, n));
      dp[i-1][i] = get_min(dp[i-1][i], dp[i-1][k] + get_dist(k, i) + get_dist(i, n) - get_dist(k, n));
    }
  }

  long double ans = LONG_MAX;
  for(int i = 1 ; i < n - 1 ; i ++) {
    ans = min(ans, dp[n-1][i]);
    ans = min(ans, dp[i][n-1]);
  }
  return ans;
}

vector<double> results;
void print_results() {
  for(auto v : results)
    printf("%lf\n", v);
}

int main(void) {
  int tc; scanf("%d\n", &tc);
  for(int i = 0; i < tc ; i++)
    results.push_back(solve());
  print_results();
  return 0;
}
