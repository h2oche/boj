#include <cstdio>

int main(void) {
	int a = 0, b = 0;
	for (int i = 1; i < 1000; i *= 10)
		a += (getchar() - '0') * i;
	getchar();
	for (int i = 1; i < 1000; i *= 10)
		b += (getchar() - '0') * i;
	printf("%d", a > b ? a : b);
	return 0;
}
