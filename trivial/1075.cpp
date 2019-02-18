#include <cstdio>
using namespace std;

int main(void) {
  int n, f; scanf("%d%d",&n,&f);
  n = (n/100)*100;
  int buf = n;
  for(; n % f != 0; n++);
  printf("%02d", n - buf);
  return 0;
}