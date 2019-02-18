#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 2001
using namespace std;

int n,m;
int buf[MAX_N] = {0,};
bool dp[MAX_N][MAX_N] = {false,};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  cin >> buf[0]; dp[0][0] = true;
  for(int i = 1 ; i < n ; i++) {
    cin >> buf[i];
    dp[i][i] = true;
    dp[i-1][i] = buf[i-1] == buf[i];
  }

  for(int l = 3 ; l <= n ; l++) {
    for(int start = 0; start <= n - l ; start++) {
      int end = start + l - 1;
      dp[start][end] = buf[start] == buf[end] ? dp[start+1][end-1] : false;
    }
  }

  cin >> m;
  for(int i = 0 ; i < m ; i ++) {
    int a, b; cin >> a >> b;
    cout << (dp[a-1][b-1] ? 1 : 0) << endl;
  }
  
  return 0;
}
