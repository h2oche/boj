#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> price(n+1, 0);
    for(int i = 1 ; i <= n ; i += 1) cin >> price[i];

    vector<int> dp(price);
    for(int i = 2 ; i <= n ; i += 1) {
        int max_price = -1;
        for(int j = 0 ; j < i ; j += 1) {
            max_price = max(max_price, dp[j] + dp[i - j]);
        }
        dp[i] = max_price;
    }

    cout << dp[n];
    return 0;
}