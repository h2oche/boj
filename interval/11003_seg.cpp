/* Fail(Time Limit) */
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, L;
vector<int> results;
vector<int> segtree;

int update(int seg_index, int seg_left, int seg_right, int target, int val) {
	if (seg_left == seg_right) return segtree[seg_index] = val;
	else if (seg_right < target || seg_left > target) return INT_MAX;
	int m = (seg_left + seg_right) / 2;

	int lv = segtree[seg_index*2], rv = segtree[seg_index*2+1];
	if (target <= m) lv = update(seg_index * 2, seg_left, m, target, val);
	else rv = update(seg_index * 2 + 1, m + 1, seg_right, target, val);
	return segtree[seg_index] = min(lv, rv);
}

int query(int seg_index, int seg_left, int seg_right, int target_left, int target_right) {
	if (target_left <= seg_left && seg_right <= target_right) return segtree[seg_index];
	else if (seg_right < target_left || target_right < seg_left) return INT_MAX;
	int m = (seg_left + seg_right) / 2;
	int lv = query(seg_index * 2, seg_left, m, target_left, target_right);
	int rv = query(seg_index * 2 + 1, m + 1, seg_right, target_left, target_right);
	return min(lv, rv);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L;

	int cnt = pow(2, (int)ceil(log2(N)) + 1);
	segtree = vector<int>(cnt, INT_MAX);

	for (int i = 1; i <= N; i++) {
		int num; cin >> num;
		update(1, 1, N, i, num);
		results.push_back(query(1, 1, N, max(i - L + 1, 1), i));
	}

	for (int r : results)
		cout << r << ' ';

	return 0;
}
