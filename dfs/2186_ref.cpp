#include <cstdio>

char a[128][128];
char s[128];
int d[2][128][128];

int main() {
	int i, j, k, l, m, n, t;
	scanf("%d%d%d", &n, &m, &l);
	for (i = 0; i < n; i++) scanf("%s", a[i]);
	scanf("%s", s);
	for (i = 0; i < n; i++) for (j = 0; j < m; j++) if (a[i][j] == *s) d[0][i][j] = 1;
	for (k = 1; s[k]; k++) {
		for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
			d[k & 1][i][j] = 0;
			if (a[i][j] == s[k]) {
				for (t = 1; t <= l && i - t >= 0; t++) d[k & 1][i][j] += d[!(k & 1)][i - t][j];
				for (t = 1; t <= l && i + t < n; t++) d[k & 1][i][j] += d[!(k & 1)][i + t][j];
				for (t = 1; t <= l && j - t >= 0; t++) d[k & 1][i][j] += d[!(k & 1)][i][j - t];
				for (t = 1; t <= l && j + t < m; t++) d[k & 1][i][j] += d[!(k & 1)][i][j + t];
			}
		}
	}
	t = 0;
	for (i = 0; i < n; i++) for (j = 0; j < m; j++) t += d[!(k & 1)][i][j];
	printf("%d", t);
	return 0;
}