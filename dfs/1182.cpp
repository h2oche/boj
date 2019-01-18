#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#define MAX_N 20
using namespace std;

int n, s;
int nums[MAX_N] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> nums[i];

	int ans = 0;

	int iter = (int)pow(2, n);
	for (int i = 1; i < iter; i += 1) {
		int psum = 0;
		for (int j = 0; j < n; j += 1)
			if ((i & 1 << j) != 0)
				psum += nums[j];

		if (psum == s) ans++;
	}

	cout << ans;

	return 0;
}
