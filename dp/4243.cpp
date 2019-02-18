#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#define MAX_N 101
using namespace std;

int n, start;
long long t[MAX_N] = {0,};
struct dp_element{
  long long cost_left, cost_right, time_left, time_right;
  dp_element() : cost_left(0), cost_right(0), time_left(0), time_right(0) {}
  bool operator==(const dp_element& de) {
    return (cost_left == de.cost_left && cost_right == de.cost_right) &&
      (time_left == de.time_left && time_right == de.time_right);
  }
};
dp_element dp[MAX_N][MAX_N];

long long get_cost(int i, int j) {
  if(i > j) {
    int temp = i;
    i = j;
    j = temp;
  }
  return t[j-1] - t[i-1];
}

void init() {
  memset(t, 0, sizeof t);
  memset(dp, 0, sizeof dp);
  cin >> n >> start;
  for(int i = 1; i < n; i++){
    int num; cin >> num;
    t[i] = t[i-1] + num;
  }
}

void update(int left, int right){
  dp_element& de1 = dp[left][right-1];
	dp_element& de2 = dp[left+1][right];
	dp_element& target = dp[left][right];
	int cnt = (left - 1) + (n - right);

	//update right
	long long time_right_right = de1.time_right + get_cost(right-1, right);
	long long right_right = de1.cost_right + time_right_right;
	long long time_right_left = de1.time_left + get_cost(left, right);
	long long right_left = de1.cost_left + time_right_left;

	long long r1 = right_left + time_right_left * cnt;
	long long r2 = right_right + time_right_right * cnt;

	if( r1 > r2 ) {
		target.cost_right = right_right;
		target.time_right = time_right_right;
	} else if(r1 < r2) {
		target.cost_right = right_left;
		target.time_right = time_right_left;
	} else {
		target.cost_right = min(right_left, right_right);
		if(right_left > right_right) {
			target.time_right = time_right_right;
		} else {
			target.time_right = time_right_left;
		}
	}

	//update left
	long long time_left_left = de2.time_left + get_cost(left+1, left);
	long long left_left = de2.cost_left + time_left_left;
	long long time_left_right = de2.time_right + get_cost(right, left);
	long long left_right = de2.cost_right + time_left_right;

	long long l1 = left_left + time_left_left * cnt;
	long long l2 = left_right + time_left_right * cnt;

	if( l1 > l2 ) {
		target.cost_left = left_right;
		target.time_left = time_left_right;
	} else if(l1 < l2) {
		target.cost_left = left_left;
		target.time_left = time_left_left;
	} else {
		target.cost_left = min(left_left, left_right);
		if(left_left > left_right) {
			target.time_left = time_left_right;
		} else {
			target.time_left = time_left_left;
		}
	}
}

long long solve() {
  init();
  long long result = 0;
  
  if(start == 1 || start == n)
    for(int i = 1; i <=n ; i++)
      result += get_cost(start, i);
  else {
		//init 2
		for(int i = start + 1 ; i <= n ; i++) {
			dp_element& prev_de = dp[start][i-1];
			dp_element& de = dp[start][i];
			de.cost_left = prev_de.cost_left + get_cost(start, i);
			de.cost_right = prev_de.cost_right + get_cost(start, i);
			de.time_left = 2 * get_cost(start, i);
			de.time_right = get_cost(start, i);
		}
		for(int i = start - 1 ; i >= 1 ; i--) {
			dp_element& prev_de = dp[i+1][start];
			dp_element& de = dp[i][start];
			de.cost_left = prev_de.cost_left + get_cost(start, i);
			de.cost_right = prev_de.cost_right + get_cost(start, i);
			de.time_left = get_cost(start, i);
			de.time_right = 2 * get_cost(start, i);
		}

		//table filling
		for(int d = 1 ; start - d >= 1 && start + d <= n; d++) {
			for(int i = start + d; i <= n ; i++)
				update(start-d, i);
			
			for(int i = start - d; i >= 1 ; i--)
				update(i, start+d);
		}

    result = min(dp[1][n].cost_left, dp[1][n].cost_right);
  }

  return result;
}

vector<long long> results;
void print_results(){
  for(auto v : results)
    cout << v << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  for(int i = 0 ; i < tc ; i ++)
    results.push_back(solve());
  print_results();
  return 0;
}
