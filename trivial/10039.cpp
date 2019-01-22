#include <iostream>
using namespace std;
int main(void) {
  int sum = 0;
  for(int i = 0 ; i < 5 ; i += 1) {
    int s; cin >> s;
    sum += s < 40 ? 40 : s;
  }
  cout << sum / 5;
  return 0;
}

