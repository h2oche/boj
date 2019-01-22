#include <iostream>
using namespace std;
int main(void) {
  int n; cin >> n;
  for(int i = 0 ; i < n ; i += 1) {
    for(int j = 0 ; j < n - i ; j += 1)
      cout << '*';
    cout << '\n';
  }
}