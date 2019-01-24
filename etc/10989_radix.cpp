#include <iostream>
#include <queue>
#include <cmath>
#define MAX 10001
#define MAX_N 10000000
using namespace std;

int n;
int d[MAX_N] = { 0, };
queue<int> bucket[10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> d[i];

	for (int i = 1; i <= 8; i++) {
		for (int j = 0; j < n; j++) {
			bucket[(d[j] / (int)pow(10, i - 1)) % (int)pow(10, i)].push(d[j]);
		}
		
		int cnt = 0;
		for (int j = 0; j < 10; j++) {
			while (!bucket[j].empty()) {
				d[cnt++] = bucket[j].front();
				bucket[j].pop();
			}
		}
	}

	return 0;
}
