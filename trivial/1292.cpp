#include <iostream>
using namespace std;

int main(void) {
  int a, b; cin >> a >> b;
  int buf[1001] = {0,};
  int cnt = 1;
  int i = 1;
  while(cnt < 1001) {
    for(int j = 1 ; j <= i && cnt < 1001 ; j ++) {
      buf[cnt++] = i;
    }
    i++;
  }
  int ans = 0;
  for(int i = a ; i <= b ; i++)
    ans += buf[i];
  cout << ans;
  return 0;
}