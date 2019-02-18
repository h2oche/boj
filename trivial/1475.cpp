#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int nums[9] = {0,};
  do {
    nums[n % 10 == 9 ? 6 : n % 10]++;
    n /= 10;
  } while (n > 0);
  int ans = (nums[6] + 1)/2;
  for(int i = 0 ; i < 9 ; i++) {
    if(i == 6) continue;
    ans = max(ans, nums[i]);
  }
  cout << ans;
  return 0;
}
