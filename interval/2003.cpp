#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int n,m;
int t[10000] = {0,};
int get_sum(int start, int end) {
  return t[end-1]-(start-1<0 ? 0 : t[start-1]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  cin >> t[0];
  for(int i = 1 ; i < n ; i++) {
    cin >> t[i];
    t[i] += t[i-1];
  }
  long long ans = 0;
  for(int l = 1; l <= n ; l++) {
    for(int i = 0; i <= n - l ;i++) {
      if(get_sum(i, i+l) == m) ans++;
    }
  }
  cout << ans;
  return 0;
}
