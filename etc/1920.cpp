#include <iostream>
#include <algorithm>
#define MAX_N 100001
using namespace std;

int buf[MAX_N] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> buf[i];
	sort(buf, buf + n);
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		if (binary_search(buf, buf + n, num)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}
