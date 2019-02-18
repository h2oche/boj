#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

long long s;

int main(void) {
	cin >> s;
	long long i;
	for(i=1;i*(i+1)/2 < s-i; i++);
	cout << i;
	return 0;
}