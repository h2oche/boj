#include <iostream>
using namespace std;
void solve(){
  int a, b; cin >> a >> b;
  cout << a + b << '\n';
}
int main(void) {
  int tc; cin >> tc;
  for(int i = 0 ; i < tc ; i ++)
    solve();
  return 0;
}