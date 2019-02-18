#include <iostream>
#define MAX_N 101
#define MAX_M 1001
using namespace std;

int n, s, m;
bool dp[MAX_N][MAX_M] = {0,};

bool check(int vol) {
	return vol <= m && vol >= 0;
}

int main(void) {
	cin >> n >> s >> m;
	for(int i = 0 ; i < n ; i++) {
		int vol; cin >> vol;
		if(i == 0) {
			if(check(s + vol)) dp[0][s+vol] = true;
			if(check(s - vol)) dp[0][s-vol] = true;
			continue;
		}
		
		for(int j = 0; j<= m ; j++) {
			if(dp[i-1][j]) {
				if(check(j + vol)) dp[i][j+vol] = true;
				if(check(j - vol)) dp[i][j-vol] = true;
			}
		}
	}
	int ans = -1;
	for(int j = 0; j <= m; j++) {
		if(dp[n-1][j]) ans = j;
	}
	cout << ans;
	return 0;
}