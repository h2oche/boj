//https://www.acmicpc.net/problem/2261
//https://www.acmicpc.net/blog/view/25
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <climits>
#include <utility>
#define N 100000
using namespace std;

struct coord{
  int x,y;
  coord() {};
  coord(int x, int y) : x(x), y(y){};
  bool operator<(const coord& c) const {
    return y != c.y ? y < c.y : x < c.x;
  }
};

int d(const coord& c1, const coord& c2) {
  int dx = abs(c1.x - c2.x); int dy = abs(c1.y - c2.y);
  return dx * dx + dy * dy;
}

bool comp_x(const coord& c1, const coord& c2) {
  return c1.x < c2.x;
}

vector<coord> p;
set<coord> candid;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for(int i = 0 ; i < n ; i += 1) {
    coord c; cin >> c.x >> c.y;
    // c.x += 10000; c.y += 10000;
    p.push_back(c);
  }
  sort(p.begin(), p.end(), comp_x);

  int start = 0;
  int ans = d(p[0], p[1]);
  candid.insert(p[0]); candid.insert(p[1]);
  for(int i = 2 ; i < p.size() ; i += 1) {
    coord now = p[i];

    // for(auto it = candid.begin() ; it != candid.end() ;) {
    //   int dx = now.x - (*it).x;
    //   if(dx * dx > ans) {
    //     it = candid.erase(it);
    //   }
    //   else {
    //     ans = min(d(now, *it), ans);
    //     it++;
    //   }
    // }
    while(start < i) {
      coord cc = p[start];
      int dx = now.x - cc.x;
      if( dx * dx > ans ) {
        candid.erase(cc);
        start++;
      } else {
        break;
      }
    }

    int dy = (int)sqrt((double)ans)+1;
    // auto b = lower_bound(candid.begin(), candid.end(), coord(0, now.y - dy), comp_y);
    // auto e = upper_bound(candid.begin(), candid.end(), coord(0, now.y + dy), comp_y);
    auto b = candid.lower_bound(coord(INT_MIN, now.y - dy));
    auto e = candid.upper_bound(coord(INT_MAX, now.y + dy));

    for(auto it = b ; it != e ; it++) {
      ans = min(d(now, *it), ans);
    }

    candid.insert(now);
  }

  cout << ans << '\n';

  return 0;
}