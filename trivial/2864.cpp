#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

pair<int, int> solve(int n) {
	int a = 0, b = 0;
	for(int i = 0 ; n != 0 ; i++, n /= 10) {
		int temp = n % 10;
		int tt = (int)pow(10, i);
		a += (temp == 5 ? 6 : temp) * tt;
		b += (temp == 6 ? 5 : temp) * tt;
	}
	return make_pair(b, a);
}

int main(void) {
	int a, b; cin >> a >> b;
	auto _a = solve(a);
	auto _b = solve(b);
	cout << _a.first + _b.first << ' ' << _a.second + _b.second;
	return 0;
}