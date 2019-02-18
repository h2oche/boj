#include <iostream>
using namespace std;

int main(void) {
	int a; cin >> a;
	int ans = 0;
	for(int i = 0 ; i < 5 ; i++) {
		int num; cin >> num;
		if(num == a) ans++;
	}
	cout << ans;
	return 0;
}