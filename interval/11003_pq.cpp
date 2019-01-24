#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N, L;
priority_queue<pair<int,int>> pq;
vector<int> results;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		pq.push(make_pair(-num, i));

		while (!pq.empty()) {
			auto min_val = pq.top();
			if (min_val.second >= i - L + 1) {
				results.push_back(-min_val.first);
				break;
			}
			pq.pop();
		}
	}

	for (int i = 0; i < N; i++)
		cout << results[i] << ' ';

	return 0;
}
