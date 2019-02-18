#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

struct dp_element {
	vector<int> cnt;
	int n;
	dp_element() {}
	dp_element(int _n, vector<int>& _data, bool add = false) {
		n = _n;
		cnt = _data;
		if(add)
			cnt.push_back(n % 2 == 0 ? 3 : 2);
	}
	int sum() {
		int ret = 0;
		for(int i = 0 ; i < cnt.size() ; i++) ret += cnt[i];
		return ret;
	}
};

int problem[1000] = {0,};
vector<dp_element> dp;

int cofac(int n) {
	if(n == 1) return 1;
	else if(n == 2) return 4;
	else return n % 2 == 0 ? 3 : 2;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc; cin >> tc;
	int max_n = 0;
	for(int i = 0 ; i < tc ; i++) {
		cin >> problem[i];
		max_n = max(max_n, problem[i]);
	}
	dp = vector<dp_element>(max(max_n+1, 4));
	vector<int> zero = {0}, one = {1}, two = {1,4}, three = {5,4,2};
	dp[0] = dp_element(0, zero);
	dp[1] = dp_element(1, one);
	dp[2] = dp_element(2, two);
	dp[3] = dp_element(3, three);
	for(int i = 4 ; i <= max_n ; i++) {
		vector<int> new_data;
		for(int j = 1 ; j < i ; j++)
			new_data.push_back(dp[i-j].sum() * cofac(j));
		dp[i] = dp_element(i, new_data, true);
	}

	for(int i = 0 ; i < tc; i++)
		cout << dp[problem[i]].sum() << '\n';

	return 0;
}