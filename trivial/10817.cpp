#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
  vector<int> v = vector<int>(3, 0);
  for(int i = 0; i < 3 ; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  cout << v[1];
  return 0;
}