#include <iostream>
using namespace std;
bool is_prime(int n) {
  if(n == 1) return false;
  for(int i = 2; i * i <= n ; i++)
    if(n % i == 0) return false;
  return true;
}

int main(void) {
  while(true) {
    int n; cin >> n;
    if(n == 0) break;
    
    int cnt = 0;
    for(int i = n + 1 ; i <= 2 * n ; i++)
      if(is_prime(i)) cnt++;
    cout << cnt << '\n';
  }
  return 0;
}