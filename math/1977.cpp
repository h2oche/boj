#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int m, n; cin >> m >> n;
  int sum = 0;
  int min_val = 100000;
  for(int i = 1 ; i * i <= n ; i++ ) {
    if(i * i >= m) {
      sum += i * i;
      min_val = min(min_val, i * i);
    }
  }
  if(sum != 0) cout << sum << '\n' << min_val;
  else cout << -1; 

  return 0;
}