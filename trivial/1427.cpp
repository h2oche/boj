#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int n; cin >> n;
  vector<int> m;

  while(n > 0) {
    m.push_back(n % 10);
    n = n / 10;
  }

  sort(m.begin(), m.end());
  for(int i = n - 1 ; i >=0 ; i--)
    cout << m[i];

  return 0;
}
