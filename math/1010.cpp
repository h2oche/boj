#include <iostream>
#define MAX_N 40
using namespace std;

long long bi[MAX_N][MAX_N] = { 0, };
void solve() {
	int n, m; cin >> n >> m;
	cout << bi[m][n] << '\n';
}

int main(void) {
	bi[1][0] = 1; bi[1][1] = 1;
	for (int i = 2; i <= MAX_N; i++) {
		bi[i][0] = 1, bi[i][i] = 1;
		for (int j = 1; j < i; j++)
			bi[i][j] = bi[i - 1][j] + bi[i - 1][j - 1];
	}

	int tc; cin >> tc;
	for(int i = 0 ; i < tc ; i ++)
		solve();
	return 0;
}