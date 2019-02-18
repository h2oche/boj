#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  map<char, int> m;
  for(int i = 0 ; i < n ; i ++) {
    string str; cin >> str;
    m[str[0]] = m[str[0]] + 1;
  }
  bool flag = true;
  for(auto kv : m) {
    if(kv.second > 4) {
      cout << kv.first;
      flag = false;
    }
  }
  if(flag) cout << "PREDAJA";
  return 0;
}