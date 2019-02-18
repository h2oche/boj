#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int min_val = INT_MAX;
  int max_val = INT_MIN;
  for(int i = 0 ; i < n ; i++) {
    int num; cin >> num;
    min_val = min(min_val, num);
    max_val = max(max_val, num);
  }
  cout << min_val << ' ' << max_val;
  return 0;
}