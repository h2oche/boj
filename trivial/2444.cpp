#include <iostream>
using namespace std;
int main(void) {
  int n; cin >> n;
  for(int i = 0 ; i < n ; i += 1) {
    for(int j = 0 ; j < n - i - 1 ; j += 1)
      cout << ' ';
    for(int j = 0; j < 2 * i + 1 ; j += 1)
      cout << '*';
    cout << '\n';
  }
  for(int i = n - 2 ; i >= 0 ; i --) {
    for(int j = 0 ; j < n - i - 1 ; j += 1)
      cout << ' ';
    for(int j = 0; j < 2 * i + 1 ; j += 1)
      cout << '*';
    cout << '\n';
  }
}