#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  queue<int> q, ans;
  for(int i = 1 ; i <= n ; i++) q.push(i);
  int tick = 1;
  while(!q.empty()) {
    int buf = q.front(); q.pop();
    if(tick % m == 0) ans.push(buf);
    else q.push(buf);
    tick++;
  }
  cout << '<';
  while(ans.size() > 1) {
    cout << ans.front() << ", ";
    ans.pop();
  }
  cout << ans.front() << '>';
  return 0;
}