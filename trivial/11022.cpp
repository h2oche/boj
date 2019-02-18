#include <iostream>
using namespace std;

void solve(int i) {
  int n, m; cin >> n >> m;
  cout << "Case #" << i << ": " << n << " + " << m << " = " << n + m << '\n';
}

int main(void) {
  int tc; cin >> tc;
  for(int i = 1 ; i <= tc ; i++)
    solve(i);
  return 0;
}