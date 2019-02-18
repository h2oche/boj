#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
/* idea : 정렬이 안된 수는 각 단계마다 최대 뒤로 한칸씩만 갈 수 있음.*/
int n;
int buf[500000] = {0,};
int buf2[500000] = {0,};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i = 0 ; i < n ; i++) cin >> buf[i], buf2[i] = buf[i];
  sort(buf, buf+n);
  int ans = 0;
  for(int i = 0; i < n ; i++) {
    auto bounds = equal_range(buf, buf+n, buf2[i]);
    int end_idx = bounds.second - buf;
    if(end_idx <= i) {
      ans = max(ans, i - end_idx + 1);
    }
  }
  cout << ans + 1;
  return 0;
}
