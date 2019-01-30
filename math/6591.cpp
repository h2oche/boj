#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n, k;
	while (true) {
		cin >> n >> k;
		if (n == 0 && k == 0) break;
		
		k = min(n-k, k);
		if (k == 0) {
			cout << 1 << '\n';
			continue;
		}

		unsigned long long result = 1;
		for (int i = n; i >= n - k + 1; i--)
			result *= i, result /= (n - i + 1);
		
		cout << result << '\n';
	}
	return 0;
}
