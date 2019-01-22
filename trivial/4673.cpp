//https://www.acmicpc.net/problem/4673
#include <iostream>
#define MAX 10001
using namespace std;
bool table[MAX] = { false, };
int d(int n) {
	int sum = n;
	while (n != 0) {
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}
int main(void) {
	for (int i = 1; i < MAX; i++) {
		int res = d(i);
		if (res >= MAX) continue;
		table[res] = true;
	}
	for (int i = 1; i < MAX; i++)
		if (!table[i])
			cout << i << '\n';
	return 0;
}
