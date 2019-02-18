#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int n,m,k;

int mul(int a, int b) {
  return ((long long)(a%k)*(b%k))%k;
}

int exp(int x, int a) {
  if(a == 0) return 1;
  if(a == 1) return x;
  if(a == 2) return mul(x, x);
  else {
    int buf = exp(x, a/2);
    return a%2==0?mul(buf,buf): mul(mul(buf,buf),x);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  cout << mul(exp(n, m), 1);
  return 0;
}
