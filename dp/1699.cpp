#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int n;
int dp[100001] = {0,};

int get_min(int a , int b) {
  if(a == 0) return b;
  else return min(a,b);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  for(int i = 1; i * i <= 100000 ; i++) dp[i*i] = 1;
  for(int i = 1 ; i <= 100000 ; i++) {
    if(dp[i] > 0) continue;
    for(int j = 1; j * j <= i ; j++) {
      if(dp[i - j * j] > 0) {
        dp[i] = get_min(dp[i], dp[i - j*j] + 1);
      }
    }
  }

  cin >> n;
  cout << dp[n];
  
  return 0;
}
