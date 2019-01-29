/* 시간초과 */
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#define MAX_N 201
using namespace std;

int n;
vector<int> buf;

int h(vector<int>& buf) {
	int sum = 0; int idx = 1;
	for (auto it = buf.begin() ; it != buf.end() ; it++, idx++)
		sum += abs((*it) - idx);
	return sum;
}

void change(vector<int>& buf, int victim, int pos) {
	int temp = buf[victim];
	buf.erase(buf.begin() + victim);
	buf.insert(buf.begin() + (victim > pos ? pos : pos - 1), temp);
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		buf.push_back(num);
	}

	int cnt = 0;
	while (h(buf) != 0) {
		vector<int> min_dist_buf = buf;
		int min_dist_val = h(buf);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n; j++) {
				if (j - i == 1 || j - i == 0) continue;
				auto c_buf = buf;
				change(c_buf, i, j);
				if (h(c_buf) < min_dist_val) {
					min_dist_buf = c_buf;
					min_dist_val = h(c_buf);
				}
			}
		}
	
		buf = min_dist_buf;
		cnt++;
	}

	cout << cnt;

	return 0;
}
