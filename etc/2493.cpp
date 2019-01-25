#include <iostream>
#include <climits>
#define MAX_N 500001
using namespace std;

int n;
int towers[MAX_N] = { 0, };
int results[MAX_N] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n; towers[0] = INT_MAX;
	for (int i = 1; i <= n; i++)
		cin >> towers[i];

	results[1] = 0;
	for (int i = 2; i <= n; i++) {
		int candid = i - 1;
		while (towers[candid] < towers[i]) {
			candid = results[candid];
		}
		results[i] = candid;
	}

	for (int i = 1; i <= n; i++)
		cout << results[i] << ' ';
}
