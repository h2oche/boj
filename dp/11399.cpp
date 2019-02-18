#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int n; cin >> n;
  vector<int> buf = vector<int>(n, 0);
  for(int i = 0 ; i < n ; i++)
    cin >> buf[i];
  sort(buf.begin(), buf.end());
  int time = 0, sum = 0;
  for(int v : buf) {
    time += v;
    sum += time;
  }
  cout << sum;
  return 0;
}