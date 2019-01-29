#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_N 1000001
using namespace std;

vector<int> seg;
pair<int, int> buf[MAX_N];

int update(int seg_index, int seg_left, int seg_right, int target, int val) {
	if (seg_right == seg_left) return seg[seg_index] = val;
	else if (seg_left > target || seg_right < target) return 0;
	int m = (seg_left + seg_right) / 2;

	int l = seg[seg_index * 2];
	int r = seg[seg_index * 2 + 1];

	if(target <= m)
		l = update(seg_index * 2, seg_left, m, target, val);
	else
		r = update(seg_index * 2 + 1, m + 1, seg_right, target, val);

	return seg[seg_index] = max(l, r);
}

int query(int seg_index, int seg_left, int seg_right, int left, int right) {
	if (seg_right < left || right < seg_left) return 0;
	else if (left <= seg_left && seg_right <= right) return seg[seg_index];
	int m = (seg_left + seg_right) / 2;
	return max(query(seg_index * 2, seg_left, m, left, right),
		query(seg_index * 2 + 1, m + 1, seg_right, left, right));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;

	int size = pow(2, (int)ceil(log2(n)) + 1) + 1;
	seg = vector<int>(size, 0);
	
	buf[0] = make_pair(-1, 0);
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		buf[i] = make_pair(num, i);
	}
	sort(buf + 1, buf + n + 1, [](auto a, auto b) -> bool {
		return a.first == b.first ? a.second > b.second : a.first < b.first;
	});
	for (int i = 1; i <= n; i++) {
		int max_val = query(1, 1, n, 1, buf[i].second);
		update(1, 1, n, buf[i].second, max_val + 1);
	}

	cout << query(1, 1, n, 1, n);

	return 0;
}
