//https://www.acmicpc.net/problem/1193
#include <iostream>
using namespace std;
int main(void) {
	int n; cin >> n;
	int i, offset;
	for (i = 1; i * (i + 1) / 2 < n; i++);
	offset = n - (i - 1) * i / 2;
	if (i % 2 == 1) cout << i + 1 - offset << '/' << offset << '\n';
	else cout << offset << '/' << i + 1 - offset << '\n';
	return 0;
}
