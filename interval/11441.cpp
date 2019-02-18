#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int n,m;
int t[100000] = {0,};
int get_sum(int start, int end) {
  return t[end-1]-(start-1<0 ? 0 : t[start-1]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  cin >> t[0];
  for(int i = 1 ; i < n ; i++) {
    cin >> t[i];
    t[i] += t[i-1];
  }
  cin >> m;
  for(int i = 0 ; i < m ; i++) {
    int start, end; cin >> start >> end;
    cout << get_sum(start-1,end) << endl;
  }
  return 0;
}
