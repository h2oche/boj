//https://www.acmicpc.net/problem/2156
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<int> elems;

int main(void) {
	cin >> n;
	elems = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> elems[i];

	if (n == 1)
		cout << elems[1];
	else if (n == 2)
		cout << elems[1] + elems[2];
	else {
		int zero = elems[1];
		int one = elems[2];
		int two = elems[1] + elems[2];

		for (int i = 3; i <= n; i += 1) {
			int new_zero = max(max(zero, one), two);
			int new_one = zero + elems[i];
			int new_two = one + elems[i];

			zero = new_zero;
			one = new_one;
			two = new_two;
		}

		cout << max(max(zero, one), two);
	}
	
	return 0;
}
