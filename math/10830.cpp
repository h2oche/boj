#include <iostream>
#include <vector>
#define MOD 1000
#define endl '\n'
using namespace std;

long long n, m;

int mul(int a, int b) {
  return ((long long)(a%MOD) * (b%MOD))%MOD;
}
int sum(int a, int b) {
  return (a%MOD+b%MOD)%MOD;
}

struct matrix {
  int n;
  vector<vector<int>> arr;

  matrix(){}
  matrix(int n):n(n) { arr = vector<vector<int>>(n,vector<int>(n, 0)); }

  matrix operator*(const matrix& m) {
    matrix ret(n);
    for(int i = 0 ; i < n ; i++)
      for(int j = 0; j < n ; j++)
        for(int k = 0; k < n ; k++)
          ret.arr[i][j] = sum(ret.arr[i][j], mul(arr[i][k], m.arr[k][j]));
    return ret;
  }
};

matrix exp(matrix m, long long n) {
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

  cin >> n >> m;
  matrix mtrx(n);
  for(int i = 0; i < n ;i++)
    for(int j = 0 ; j < n; j++)
      cin >> mtrx.arr[i][j], mtrx.arr[i][j] = mtrx.arr[i][j] % MOD;
  auto ans = exp(mtrx, m);
  for(int i = 0; i < n ;i++) {
    for(int j = 0 ; j < n; j++) {
      cout << ans.arr[i][j] << ' ';
    }
    cout << endl;
  }
	return 0;
}