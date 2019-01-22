#include <iostream>
#include <string>
using namespace std;
int main(void) {
  int n; cin >> n;
  int sum = 0;
  for(int i = 0 ; i < n ; i ++) {
    char c = cin.get() - '0';
    sum += (int)c;
  }
  cout << sum;
  return 0;
}