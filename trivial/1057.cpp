#include <iostream>
using namespace std;

int main(void) {
  int n, a, b; cin >> n >> a >> b;
  int rnd = 1;
  a = (a-1)/2;
  b = (b-1)/2;
  while(a != b) {
    a = a / 2;
    b = b / 2;
    rnd++;
  }
  cout << rnd;
  return 0;
}