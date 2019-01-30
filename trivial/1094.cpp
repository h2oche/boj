#include <iostream>
using namespace std;

int main(void) {
	int n; cin >> n;
	int cnt = 0;
	while (n > 0) {
		cnt += n % 2;
		n = n / 2;
	}
	cout << cnt;
	return 0;
}
