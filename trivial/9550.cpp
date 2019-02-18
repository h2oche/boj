#include <iostream>
using namespace std;
void solve() {
	int n, k; cin >> n >> k;
	int ans = 0;
	for(int i = 0 ; i < n ; i++) {
		int num; cin >> num;
		ans += num / k;
	}
	cout << ans << '\n';
}
int main(void){
	int tc; cin >> tc;
	for(int i = 0 ; i < tc; i++)
		solve();
	return 0;
}