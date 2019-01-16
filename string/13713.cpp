//https://www.acmicpc.net/problem/13713
#include <cstdio>
#include <vector>
#include <string>
#define N 1000000
using namespace std;

char buf[N+1];
int m;
int main(void)
{
  scanf("%s\n", buf);
  scanf("%d\n", &m);
  for(int i = 0 ; i < m ; i += 1) {
    int num; scanf("%d\n", &num);
  }

  printf("%s\n", buf);

  return 0;
}