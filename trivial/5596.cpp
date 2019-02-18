#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int a = 0, b = 0;
	for(int i = 0 ; i < 4 ; i++) {
		int num; cin >> num;
		a += num;
	}
	for(int i = 0 ; i < 4 ; i++) {
		int num; cin >> num;
		b += num;
	}
	cout << max(a, b);
	return 0;
}