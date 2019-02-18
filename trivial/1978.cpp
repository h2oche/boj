#include <iostream>
using namespace std;
bool is_prime(int n) {
  if(n == 1) return false;
  for(int i = 2; i * i <= n ; i++)
    if(n % i == 0) return false;
  return true;
}

int main(void) {
  int n; cin >> n;
  int cnt = 0;
  for(int i = 0 ; i < n ; i++){
    int num; cin >> num;
    if(is_prime(num)) cnt++;
  }
  cout << cnt;
  return 0;
}