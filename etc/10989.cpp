#include <iostream>
#define MAX 10001
#define MAX_N 10000000
using namespace std;

int histo[MAX] = { 0, };
int n;
//int d[MAX_N] = { 0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		histo[num]++;
	}
	
	for (int i = 1; i < MAX; i++)
		histo[i] += histo[i - 1];

	for (int i = 0; i < MAX - 1; i++) {
		for (int j = histo[i]; j < histo[i + 1]; j++) {
			cout << i + 1 << '\n';
		}
	}
	return 0;
}
