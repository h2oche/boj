#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#define MAX_N 500000
#define RANGE 8001
using namespace std;

int d[MAX_N] = { 0, };
pair<int,int> histo[RANGE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < RANGE; i++)
		histo[i] = make_pair(0, i);

	int n; cin >> n; long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		sum += d[i];
		histo[d[i] + 4000].first++;
	}

	//mean
	cout << floor(sum / (double)n + 0.5) << '\n';

	//median
	sort(d, d + n);
	cout << d[n / 2] << '\n';

	//mode
	sort(histo, histo + RANGE);
	int max_val = (*max_element(histo + 0, histo + RANGE)).first;
	auto bounds = equal_range(histo + 0, histo + RANGE, make_pair(max_val, 0), [](auto a, auto b) -> bool {
		return a.first < b.first;
	});

	int mode = (*(bounds.first)).second;
	if (bounds.second - bounds.first > 1)
		mode = (*(bounds.first + 1)).second;

	cout << mode - RANGE / 2 << '\n';

	//min max
	auto mm = minmax_element(d+0, d + n);
	cout << *mm.second - *mm.first;
	
	return 0;
}
