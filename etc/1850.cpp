#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
	long long r;
	if (a < b) r = a, a = b, b = r;
	do {
		r = a % b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}
int buf[100] = { 0, };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b; cin >> a >> b;
	long long lp = gcd(a, b);
	for (int i = 0; i < lp; i++)
		cout << '1';
	return 0;
}
