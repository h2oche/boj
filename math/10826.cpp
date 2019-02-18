#include <vector>
#include <iostream>
#include <algorithm>
#define THRESHOLD 1000000000
using namespace std;

struct big_integer {
  vector<int> d;
  big_integer(int a) {
    d.push_back(a);
  }
  big_integer operator+(const big_integer& bi) {
    big_integer ret(0);
    ret.d.resize(max(bi.d.size(), d.size()));

    int acc = 0;
    for(int i = 0 ; i < max(bi.d.size(), d.size()) ;i++) {
      int test = acc;
      if(i < bi.d.size()) test += bi.d[i];
      if(i < d.size()) test += d[i];

      if(test >= THRESHOLD) {
        ret.d[i] = test % THRESHOLD;
        acc = test / THRESHOLD;
      } else {
        ret.d[i] = test;
        acc = 0;
      }
    }
    if(acc > 0) ret.d.push_back(acc);
    return ret;
  }
  big_integer operator+=(const big_integer& bi) {
    *this = *this + bi;
    return *this;
  }
  friend ostream& operator<<(ostream& cin, const big_integer& bi) {
    cout << bi.d.back();
    for(int i = bi.d.size() - 2 ; i>=0 ; i--)
      printf("%09d",bi.d[i]);
    return cin;
  }
};

int main(void) {
  int n; cin >> n;
  big_integer a = 0, b = 1;
  for(int i = 2 ; i <= n ; i++) {
    big_integer temp = b;
    b += a;
    a = temp;
  }
  if(n == 0) cout << 0;
  else cout << b;
  return 0;
}