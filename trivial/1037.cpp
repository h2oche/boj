#include <iostream>
#include <algorithm>
#define MAX_N 51
using namespace std;

int n;
int buf[MAX_N] = {0,};

int main(void) {
  cin >> n;
  for(int i = 0 ; i < n ; i++) cin >> buf[i];
  sort(buf, buf+n);
  cout << buf[0] * buf[n-1];
  return 0;
}