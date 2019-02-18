#include <iostream>
#include <algorithm>
using namespace std;
bool is_prime(int n) {
  if(n == 1) return false;
  for(int i = 2; i * i <= n ; i++)
    if(n % i == 0) return false;
  return true;
}

int main(void) {
  int n, m; cin >> m >> n;
  bool print_minus = true;
  int sum=0;
  int min_val=10001;
  for(int i = m ; i <= n ; i++) {
    if(is_prime(i)) {
      sum += i;
      min_val = min(i, min_val);
      print_minus = false;
    }
  }
  if(print_minus) cout << "-1";
  else {
    cout << sum << '\n';
    cout << min_val;
  }
  return 0;
}