#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

int n;
priority_queue<int> pq;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    int num; cin >> num;
    if(num == 0) {
      if(pq.size() == 0) cout << 0 << endl;
      else {
        cout << -pq.top() << endl;
        pq.pop();
      }
    }
    else pq.push(-num);
  }
  
  return 0;
}
