#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#define endl '\n'
#define MAX_N 500001
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n,m;
int buf[MAX_N] = {0,};
stack<pii> s;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i = 0 ; i < n ; i++) cin >> buf[i];
  s.push(pii(buf[0], 1));

  ll ans = 0;
  for(int i = 1 ; i < n ; i++) {
    while(!s.empty() && s.top().first < buf[i]) {
      ans += s.top().second;
      s.pop();
    }

    if(s.empty()) {
      s.push(pii(buf[i],1));
    }
    else if(buf[i] < s.top().first) {
      ans ++;
      s.push(pii(buf[i],1));
    }
    else if(buf[i] == s.top().first) {
      if(s.size() >= 2) {
        ans++;
      }
      ans += s.top().second;
      s.top().second++;
    }
  }
  cout << ans;
  return 0;
}
