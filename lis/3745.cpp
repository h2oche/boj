#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int buf[MAX_N] = { 0, };
void solve() {
  int n = 0; cin >> n;
  if(n == 0) return;

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

	cout << dp.size() << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
  while(!cin.eof())
    solve();
	return 0;
}
