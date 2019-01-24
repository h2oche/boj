#include <iostream>
using namespace std;
int main(void) {
  int c = 0xfffffff;
  float d = 0xfffffff;
  double e = 0xfffffff;
  printf("%d %d %d", c == d, d == e, e == c);
  return 0;
}