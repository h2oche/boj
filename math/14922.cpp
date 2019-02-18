#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 1000000
using namespace std;
/* idea : 가장 작은 평균의 구간은 2 또는 3일 수밖에 없다 */
int n;
long long buf[MAX_N]={0,};
double get_sum(int l, int r) {
  if(l == 0) return buf[r];
  else return buf[r]-buf[l-1];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> buf[0];
  for(int i = 1 ; i < n; i++) {
    cin >> buf[i];
    buf[i] += buf[i-1];
  }
  double min_val = 1000000000;
  int ans = 0;
  for(int i = 0 ; i < n - 2; i++) {
    double test = get_sum(i, i+1) / 2;
    double test2 = get_sum(i, i+2) / 3;

    if(min(test, test2) < min_val) {
      min_val = min(test, test2);
      ans = i;
    }
  }
  if(min_val > get_sum(n-2,n-1)/2)
    ans = n-2;

  cout << ans;
  
  return 0;
}
