#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int r, a, b; cin >> r >> a >> b;
  double x = (double)r / sqrt(a * a + b * b);
  cout << (int)floor(x * a) << ' ' << (int)floor(x * b);
  return 0;
}