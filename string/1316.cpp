#include <iostream>
#include <string>
#include <set>
using namespace std;

bool check() {
  string str; cin >> str;
  set<char> s;
  for(int i = 0 ; i < str.size();) {
    char buf = str[i];
    if(s.count(buf) > 0) return false;
    for(;buf == str[i];i++);
    s.insert(buf);
  }
  return true;
}

int main(void) {
  int n; cin >> n;
  int ans = 0;
  for(int i = 0 ; i < n ; i ++)
    if(check()) ans++;
  cout << ans;
  return 0;
}