#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
#include <string>
using namespace std;

string buf;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> buf;
	long long ans = 0;
	stack<char> s; 
	for(int i = 0 ; i < buf.size() ; i++) {
		if(buf[i] == '(') s.push('(');
		else {
			s.pop();
			ans += buf[i-1] == '(' ? s.size() : 1;
		}
	}
	cout << ans;
	return 0;
}