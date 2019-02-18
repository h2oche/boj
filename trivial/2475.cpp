#include <iostream>
using namespace std;

int main(void) {
	int res = 0;
	for(int i = 0 ; i < 5 ; i++) {
		int num; cin >> num;
		res += num * num;
	}
	cout << res % 10;
	return 0;
}