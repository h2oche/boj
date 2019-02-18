#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
	int r;
	do {
		r = a % b;
		a = b;
		b = r;
	} while (r != 0);
	return a;
}
int main(void) {
  int n; cin >> n;
	vector<int> buf;
	for(int i = 0 ; i < n ;i++) {
		int num; cin >> num;
		buf.push_back(num);
	}
	int g = gcd(buf[0], buf[1]);
	if(n == 3) g = gcd(g, buf[2]);
	set<int> s;
	for(int i = 1 ; i <= (int)sqrt(g); i++) {
		if(g % i == 0) {
			s.insert(i);
			s.insert(g/i);
		}
	}
	for(auto v : s)
		cout << v << '\n';
  return 0;
}