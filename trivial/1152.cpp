#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void) {
  int cnt = 0;
  while(!cin.eof()) {
    string str;
    cin >> str;
    cnt += 1;
    if(str == "") cnt -= 1;
  }
  cout << cnt;
  
  return 0;
}