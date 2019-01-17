//https://www.acmicpc.net/problem/1697
#include <queue>
#include <iostream>
#include <utility>
#define MAX 100000

using namespace std;

int n, k;
bool v[MAX + 1] = {false,};
queue<pair<int, int>> q;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;

  int ans = 0;

  if(n != k) {
    q.push(make_pair(n, 0));
    v[n] = true;

    while(true) {
      ans ++;

      pair<int, int> new_n = q.front(); q.pop();
      vector<int> candids = {new_n.first + 1, new_n.first - 1, new_n.first * 2};
      bool found = false;

      for(int candid : candids) {
        if(candid <= MAX && candid >=0 && !v[candid]) {
          if(candid == k) {
            ans = new_n.second + 1;
            found = true;
            break;
          }

          v[candid] = true;
          q.push(make_pair(candid, new_n.second+1));
        }
      }

      if(found) break;
    }
  }

  cout << ans;

  return 0;
}
