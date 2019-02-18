#include <cstdio>
using namespace std;

int main(void) {
  char buf; bool print = true;
  while( (buf = getchar()) != EOF) {
    if(print) {
      putchar(buf);
      print = false;
      continue;
    }

    if(buf == '-') print = true;
  }
  return 0;
}