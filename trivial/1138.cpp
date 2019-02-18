#include <iostream>
using namespace std;

int n;
int buf[11] = {0,};
int result[11] = {0,};
int count(int idx) {
  int ret = 0;
  for(int i = 0; i < idx ; i++)
    if(result[i] == 0) ret++;
  return ret;
}

int main(void) {
  cin >> n;
  for(int i = 0 ; i < n ; i++) cin >> buf[i];
  result[buf[0]] = 1;
  for(int i = 1 ; i < n ; i++) {
    int start = buf[i];
    while(start < n) {
      if(result[start] == 0 && buf[i] == count(start)) {
        result[start] = i + 1;
        break;
      }
      start++;
    }
  }
  for(int i = 0 ; i < n ; i++) cout << result[i] << ' ';
  return 0;
}