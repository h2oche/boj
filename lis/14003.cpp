#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX_N 1000000
using namespace std;

int buf[MAX_N] = { 0, };
int rec[MAX_N] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf[i];
		rec[i] = -1;
	}

	vector<pair<int, int>> dp; dp.push_back(make_pair(buf[0], 0));
	for (int i = 1; i < n; i++) {
		if (dp.back().first < buf[i]) {
			rec[i] = dp.back().second;
			dp.push_back(make_pair(buf[i], i));			
		}
		else {
			auto it = lower_bound(dp.begin(), dp.end(), make_pair(buf[i], i), [](auto a, auto b)->bool {
				return a.first < b.first;
			});
			*it = make_pair(buf[i], i);
			if (it != dp.begin()) {
				auto prev_it = it - 1;
				rec[i] = (*prev_it).second;
			}
		}
	}

	cout << dp.size() << '\n';
	stack<int> results;
	results.push(dp.back().first);

	int next = rec[dp.back().second];
	while (next != -1) {
		results.push(buf[next]);
		next = rec[next];
	}

	while (!results.empty()) {
		cout << results.top() << ' ';
		results.pop();
	}
	return 0;
}
