#include <iostream>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	int r;
	if (a < b) r = a, a = b, b = r;
	do {
		r = a % b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}

int m[100] = { 0, };
set<int> nums;
queue<int> q;

int main(void) {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> m[i];

	for (int i = 0; i < n - 1; i++)
		nums.insert(abs(m[i] - m[i + 1]));

	for (auto v : nums)
		q.push(v);

	while (q.size() > 1) {
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		q.push(gcd(a, b));
	}

	int max_val = q.front();
	vector<int> ans; ans.push_back(max_val);
	for (int i = 2; i*i <= max_val; i++) {
		if (max_val % i == 0) {
			ans.push_back(i);
			if( max_val / i != i)
				ans.push_back(max_val / i);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto v : ans)
		cout << v << ' ';

	return 0;
}
