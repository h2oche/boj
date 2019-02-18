#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> buf;
	for(int i = 1 ; i <= n ; i++) buf.push_back(i);
	do {
		for(int i = 0 ; i < buf.size(); i ++) cout << buf[i] << ' ';
		cout << '\n';
	} while(next_permutation(buf.begin(), buf.end()));
	return 0;
}