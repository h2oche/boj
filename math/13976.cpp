#include <iostream>
#define MOD 1000000007
using namespace std;

long long n;
int s1 = 3;
int s2 = 14;

int mul(int a, int b) {
  return ((long long)(a%MOD) * (b%MOD))%MOD;
}
int sum(int a, int b) {
  return (a%MOD+b%MOD)%MOD;
}

struct matrix {
  int a, b, c, d;
  matrix() : a(0), b(0), c(0), d(0) {}
  matrix(int a, int b, int c, int d): a(a), b(b), c(c), d(d) {}
  matrix operator*(const matrix& m) {
    matrix ret;
    ret.a = sum(mul(a, m.a), mul(b, m.c));
    ret.b = sum(mul(a, m.b), mul(b, m.d));
    ret.c = sum(mul(c, m.a), mul(d, m.c));
    ret.d = sum(mul(c, m.b), mul(d, m.d));
    return ret;
  }
};

matrix exp(matrix m, long long n) {
  if(n == 0) return matrix(1,0,1,0);
  if(n == 1) return m;
  else if(n == 2) return m*m;
  else{
    matrix buf = exp(m, n/2);
    return n%2 == 0 ? buf*buf : buf*buf*m;
  }
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

  cin >> n;
  long long ans = 0;
  if(n % 2 == 1) ans = 0;
  else {
    n = n / 2;
    if(n == 1) ans = s1;
    else if(n == 2) ans = s2 - s1;
    else {
      matrix key, temp;
      key.a = 4, key.b = MOD - 1, key.c = 1, key.d = 0;
      temp = exp(key, n-2);
      int a = sum(mul(temp.a, 15), mul(temp.b, 4));
      int b = sum(mul(temp.c, 15), mul(temp.d, 4));
      ans = sum(a, MOD-b);
    }
  }
	cout << ans;
	return 0;
}