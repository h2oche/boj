#include <iostream>
#include <string>
using namespace std;
int main(void) {
  int x, y; cin >> x >> y;
  int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string ys[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  int td = y;
  for(int i = 1 ; i < x ; i++)
    td += days[i];
  cout << ys[td % 7];
  return 0;
}