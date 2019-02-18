#include <cstdio>
using namespace std;
char buf[9];

int main(void) {
  int cnt = 0;
  bool flag = false;
  while(~scanf("%s\n", buf)) {
    for(int i = 0 ; i < 8 ; i++)
      if(buf[i] == 'F' && i % 2 == (flag ? 1 : 0))
        cnt++;
    flag = !flag;
  }
  printf("%d", cnt);
  return 0;
}