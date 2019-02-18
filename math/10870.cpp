#include <iostream>
using namespace std;

int main(void) {
  int n; cin >> n;
  long long a = 0, b = 1;
  for(int i = 2 ; i <= n ; i++) {
    long long temp = b;
    b += a;
    a = temp;
  }
  if(n == 0) cout << 0;
  else cout << b;
  return 0;
}