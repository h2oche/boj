#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 40000
using namespace std;

int buf[MAX_N] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> buf[i];

	vector<int> dp; dp.push_back(buf[0]);
	for (int i = 1; i < n; i++) {
		if (dp.back() < buf[i])
			dp.push_back(buf[i]);
		else {
			auto it = lower_bound(dp.begin(), dp.end(), buf[i]);
			*it = buf[i];
		}
	}

	cout << dp.size();

	return 0;
}
