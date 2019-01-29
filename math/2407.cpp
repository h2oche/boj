#include <iostream>
#include <climits>
#define MAX_N 101
#define THRESHOLD 1000000000000000000
using namespace std;

struct big_integer {
	long long l1, l2;
	big_integer() : l1(0), l2(0){};

	big_integer& operator=(const int a) {
		l1 = a;
		return *this;
	}
	big_integer operator+(const big_integer& elem) {
		big_integer ret;
		ret.l2 = l2 + elem.l2;

		if (l1 + elem.l1 > THRESHOLD) {
			ret.l2 += (l1 + elem.l1) / THRESHOLD;
			ret.l1 = l1 + elem.l1 - THRESHOLD;
		}
		else {
			ret.l1 = l1 + elem.l1;
		}

		return ret;
	}

	friend ostream& operator<<(ostream& cin, const big_integer& elem) {
		if (elem.l2 != 0)
			cout << elem.l2;
		cout << elem.l1;
		return cin;
	}
};

big_integer bi[MAX_N][MAX_N];

int main(void) {
	int n, m; cin >> n >> m;
	bi[1][0] = 1; bi[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		bi[i][0] = 1, bi[i][i] = 1;
		for (int j = 1; j < i; j++)
			bi[i][j] = bi[i - 1][j] + bi[i - 1][j - 1];
	}
	cout << bi[n][m];
	return 0;
}
