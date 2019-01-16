//https://www.acmicpc.net/blog/view/9
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> a;
vector<long long> segtree;
vector<long long> lazy;

long long init(int index, int start, int end) {
  if(start == end) return segtree[index] = a[start];
  return segtree[index] = init(index * 2, start, (start + end) / 2) + init(index * 2 + 1, (start + end) / 2 + 1, end);
}

long long get(int index, int start, int end, int left, int right) {
  if( start > right || end < left) return 0;
  if( left <= start && end <= right) return segtree[index];
  return get(index * 2, start, (start + end) / 2, left, right) + get(index * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

long long get_one(int index, int start, int end, int target) {
  if(start == end) return segtree[index];
  if( start <= target && target <= (start + end)/2)
    return get_one(index * 2 , start, (start + end)/2, target);
  else
    return get_one(index * 2 + 1, (start + end)/2 + 1, end, target);
}

void update_one(int index, int start, int end, int target, long long diff) {
  if( start > target || end < target ) return;
  segtree[index] += diff;
  if( start != end) {
    update_one(index * 2, start, (start + end)/ 2, target, diff);
    update_one(index * 2 + 1, (start + end)/2 + 1, end, target, diff);
  }
}

int main(void)
{
  int n, m, k;
  cin >> n >> m >> k;
  segtree = vector<long long>( 1 << ((int)ceil(log2(n)) + 1) );
  lazy = vector<long long>(segtree);

  for(int i = 0 ; i < n ; i += 1){
    int num; cin >> num;
    a.push_back(num);
  }

  init(1, 0, n - 1);

  for(int i = 0 ; i < m + k ; i += 1) {
    int op, p1, p2;
    int res;
    cin >> op >> p1 >> p2;

    switch(op) {
    case 1:
      res = get_one(1,0,n-1,p1-1);
      update_one(1, 0, n-1, p1 - 1, p2 - res);
      break;
    case 2:
      cout << get(1, 0, n-1, p1 - 1, p2 - 1) << '\n';
    break;
    }
  }

  return 0;
}