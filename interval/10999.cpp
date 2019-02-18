#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
using namespace std;

int N, M, K;
vector<long long> segtree, lazy;

long long update(int seg_index, int seg_left, int seg_right, int left, int right, long long diff) {
  if(seg_right < left || right < seg_left)
    return segtree[seg_index] + lazy[seg_index] * (seg_right - seg_left + 1);
  if(left <= seg_left && seg_right <= right) {
    segtree[seg_index] += (diff + lazy[seg_index]) * (seg_right - seg_left + 1);
    /* lazy propagation */
    if(seg_left != seg_right) {
      lazy[seg_index*2] += diff + lazy[seg_index];
      lazy[seg_index*2+1] += diff + lazy[seg_index];
    }
    lazy[seg_index] = 0;
    return segtree[seg_index];
  }
  /* lazy propagation */
  lazy[seg_index*2] += lazy[seg_index];
  lazy[seg_index*2+1] += lazy[seg_index];
  lazy[seg_index] = 0;
  
  int m = (seg_left + seg_right) / 2;

  long long lv = update(seg_index*2, seg_left, m, max(seg_left, left), min(m, right), diff);
  long long rv = update(seg_index*2+1, m+1, seg_right, max(m+1, left), min(seg_right, right), diff);
  return segtree[seg_index] = lv + rv;
}

long long query(int seg_index, int seg_left, int seg_right, int left, int right) {
	if(seg_right < left || right < seg_left) return 0;
  if(left <= seg_left && seg_right <= right)
    return segtree[seg_index] + lazy[seg_index] * (seg_right - seg_left + 1);
  int m = (seg_left + seg_right)/2;
  long long lv = query(seg_index*2, seg_left, m, left, right);
  long long rv = query(seg_index*2+1, m+1, seg_right, left, right);
  return lv + rv + lazy[seg_index] * (min(right, seg_right) - max(seg_left, left) + 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;

	int cnt = pow(2, (int)ceil(log2(N)) + 1);
	segtree = vector<long long>(cnt, 0);
  lazy = vector<long long>(cnt, 0);

	for (int i = 1; i <= N; i++) {
		int num; cin >> num;
		update(1, 1, N, i, i, num);
	}

  for(int i = 0 ; i < M + K ; i++) {
    int op, a, b, c; cin >> op >> a >> b;
    if(op == 1) {
      cin >> c;
      update(1, 1, N, a, b, c);
    }
    else cout << query(1, 1, N, a, b) << endl;
  }

	return 0;
}

