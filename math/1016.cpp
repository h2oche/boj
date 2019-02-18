#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

ll n,m;
bool check[1000001] = {false,};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;

  ll ans = m - n + 1;
  
  for(ll i = 2 ; i * i <= m; i ++)
    for(ll j = (n / (i*i))*(i*i) ; j <= m ; j += i*i)
      if( j>=n && !check[j-n] )
        check[j-n] = true, ans--;

  cout << ans;
  
  return 0;
}
