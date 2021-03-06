#include <iostream>
#define MAX 2000002
#define B 1000001
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
		histo[num + B]++;
	}

	for (int i = 1; i < MAX; i++)
		histo[i] += histo[i - 1];

	for (int i = 0; i < MAX - 1; i++) {
		for (int j = histo[i]; j < histo[i + 1]; j++) {
			cout << (i + 1 - B) << '\n';
		}
	}

	return 0;
}
