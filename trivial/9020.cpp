#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool is_prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

vector<pair<int,int>> results;
pair<int, int> solve() {
	int num; cin >> num;
	for (int i = num/2; i > 1; i--)
		if (is_prime(i) && is_prime(num - i))
			return make_pair(i, num - i);
}

void print_ans() {
	for (auto res : results)
		cout << res.first << ' ' << res.second << '\n';
}

int main(void) {
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++)
		results.push_back(solve());
	print_ans();
	return 0;
}
