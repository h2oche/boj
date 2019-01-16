//https://www.acmicpc.net/problem/2357
#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <cmath>
using namespace std;

vector<long long> a;
vector<pair<long long, long long> > tree;

pair<long long, long long> init(int index, int start, int end) {
  if(start == end) return tree[index] = pair<long long, long long>(a[start], a[start]);
  auto p1 = init(index * 2, start, (start + end)/ 2);
  auto p2 = init(index * 2 + 1, (start + end)/2 +1, end);
  return tree[index] = pair<long long, long long>(min(p1.first, p2.first), max(p1.second, p2.second));
}

void get(int index, int start, int end, int left, int right, pair<long long, long long>& res) {
  if(right < start || end < left) return;
  if( left <= start && end <= right) {
    res.first = min(res.first, tree[index].first);
    res.second = max(res.second, tree[index].second);
    return;
  }
  get(index * 2, start, (start + end)/2, left, right, res);
  get(index * 2 + 1, (start + end)/2 + 1, end, left, right, res);
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  int size = 1 << ((int)ceil(log2(n)) + 1);
  a = vector<long long>(n+1);
  a.push_back(0);
  tree = vector<pair<long long, long long>>(size);
  for(int i = 0 ; i < n ; i += 1) {
    int num; cin >> num;
    a.push_back(num);
  }
  init(1, 1, n);
  // for(int i = 1 ; i <= size ; i += 1) {
  //   cout << i << " : " << a[i] << ", " << tree[i].first << ", " << tree[i].second << endl;
  // }
  for(int i = 0; i < m ; i += 1) {
    int a,b; cin >> a >> b;
    pair<long long, long long> res = make_pair(LONG_MAX, LONG_MIN);
    get(1, 1, n, a, b, res);
    cout << res.first << ' ' << res.second << '\n';
  }
  return 0;
}