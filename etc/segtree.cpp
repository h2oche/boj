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

void update_one(int index, int start, int end, int target, long long diff) {
  if( start > target || end < target ) return;
  segtree[index] += diff;
  if( start != end) {
    update_one(index * 2, start, (start + end)/ 2, target, diff);
    update_one(index * 2 + 1, (start + end)/2 + 1, end, target, diff);
  }
}

long long update_range(int index, int start, int end, int left, int right, long long diff) {
  if( start > right || end < left) return 0;
  if( start == end ) return segtree[index] += diff;
  update_range(index * 2, start, (start + end)/2, left, right, diff);
  update_range(index * 2 + 1, (start + end)/2 + 1, end, left, right, diff);
  return segtree[index] = segtree[index * 2] + segtree[index * 2 + 1];
}

/* lazy propagation of segment tree */
//https://www.acmicpc.net/blog/view/26

void update_lazy(int index, int start, int end) {
  if(lazy[index] != 0) {
    segtree[index] += (end - start + 1) * lazy[index];
    if(start != end) {
      lazy[index * 2] = lazy[index];
      lazy[index * 2 + 1] = lazy[index];
    }
    lazy[index] = 0;
  }
}

long long get_lazy(int index, int start, int end, int left, int right) {
  update_lazy(index, start, end);
  if( left <= start && end <= right) return segtree[index];
  return get_lazy(index * 2, start, (start + end)/2, left, right) + get_lazy(index * 2 + 1, (start + end)/2 + 1, end, left, right);
}

void update_range_lazy(int index, int start, int end, int left, int right, long long diff) {
  if( start > right || end < left ) return;
  update_lazy(index, start, end);
  if( left <= start && end <= right ) {
    segtree[index] += (end - start + 1) * diff;
    if(start != end) {
      lazy[index * 2] = diff;
      lazy[index * 2 + 1] = diff;
    }
    return;
  }
  update_range_lazy(index * 2, start, (start + end)/2, left, right, diff);
  update_range_lazy(index * 2 + 1, (start + end)/2 + 1, end, left, right, diff);
  segtree[index] = segtree[index * 2] + segtree[index * 2 + 1];
}

int main(void)
{
  int n;
  cin >> n;
  segtree = vector<long long>( 1 << ((int)ceil(log2(n)) + 1) );
  lazy = vector<long long>(segtree);

  for(int i = 0 ; i < n ; i += 1){
    int num; cin >> num;
    a.push_back(num);
  }

  init(1, 0, n - 1);

  // cout << get(1, 0, n-1, 2, 4);
  // // update_one(1,0,n-1,3,4);
  // update_range(1, 0, n-1, 3, 4, 2);
  update_range_lazy(1, 0, n-1, 2, 4, 2);

  for(int i = 0 ; i < segtree.size() ; i += 1) {
    cout << i << " : " << segtree[i] << "(" << lazy[i] << ")" << endl;
  }

  return 0;
}