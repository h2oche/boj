#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
  int x, y, w, h; cin >> x >> y >> w >> h;
  cout << min(min((int)abs(x - w), x), min((int)abs(y - h), y));
  return 0;
}