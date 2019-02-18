#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 100000
using namespace std;

struct coord {
  int x, y;
  bool operator<(const coord& c) const {
    return y == c.y ? x < c.x : y < c.y;
  }
};
int n;
coord buf[MAX_N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> buf[i].x >> buf[i].y;
  sort(buf, buf+n);
  for(int i = 0 ; i < n ; i++)
    cout << buf[i].x << ' ' << buf[i].y << endl;
  return 0;
}
