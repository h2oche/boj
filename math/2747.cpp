#include <vector>
#include <iostream>
using namespace std;

int main(void) {
  int n; cin >> n;
  int a = 0, b = 1;
  for(int i = 2 ; i <= n ; i++) {
    int temp = b;
    b += a;
    a = temp;
  }
  cout << b;
  return 0;
}