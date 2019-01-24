#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n ; cin >> n;
  vector<int> buf = vector<int>(n,0);
  for(int i = 0 ; i < n ; i ++)
    cin >> buf[i];
  sort(buf.begin(), buf.end());
  for(int i = 0 ; i < n ; i++)
    cout << buf[i] << '\n';
  return 0;
}