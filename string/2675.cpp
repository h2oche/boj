#include <iostream>
#include <string>
using namespace std;

void solve(){
	int n; string str; cin >> n >> str;
	for(int i = 0 ; i < str.size(); i++) {
		for(int j = 0 ; j < n ; j++) {
			putchar(str[i]);
		}
	}
	putchar('\n');
}

int main(void) {
	int tc; cin >> tc;
	for(int i = 0 ; i < tc; i++)
		solve();
	return 0;
}