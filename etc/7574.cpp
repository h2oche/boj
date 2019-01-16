#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <utility>
#include <algorithm>
using namespace std;

struct plane{
  int x,y,r;
  plane(){}
  plane(int r): r(r){}
  plane(int x, int y, int r): x(x), y(y), r(r){}
  bool accessible(const plane& p, int d) const {
    auto corners = p.corners();
    for(auto xy : corners) {
      int x = xy.first; int y = xy.second;
      if((this->x - d <= x && x <= this->x + r + d && this->y <= y && y <= this->y + r ) ||
          (this->y - d <= y && y <= this->y + r + d && this->x <= x && x <= this->x + r) ){
        return true;
      }
    }
    return false;
  }
  vector<pair<int, int>> corners() const {
    return {make_pair(x,y), make_pair(x+r,y), make_pair(x,y+r), make_pair(x+r,y+r)};
  }
  bool operator<(const plane& p) const {
    return y != p.y ? y < p.y : x < p.x;
  }
};

bool comp(const plane& p1, const plane& p2) {
  return p1.x < p2.x;
}

int n, d, r;
vector<plane> planes;
set<plane> candid;
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> r;
  for(int i = 0 ; i < n ; i += 1) {
    plane p(r); cin >> p.x >> p.y;
    planes.push_back(p);
  }
  cin >> d;
  sort(planes.begin(), planes.end(), comp);

  int ans = 0;
  int start = 0;
  candid.insert(planes[0]);

  for(int i = 1 ; i < n ; i += 1) {
    const plane now = planes[i];

    while(start < i) {
      if(now.x - d > planes[start].x + r) {
        candid.erase(planes[start]);
        start++;
      } else {
        break;
      }
    }

    auto b = candid.lower_bound(plane(INT_MIN, now.y - r - d, r));
    auto e = candid.upper_bound(plane(INT_MAX, now.y + r + d, r));
    bool check =
    any_of(b, e, [&now](const plane& p){
      return p.accessible(now, d);
    });
    if(check) {
      ans = max(ans, now.x + now.y);
      candid.insert(now);
    }
  }

  cout << ans + r * 2<< '\n';

  return 0;
}