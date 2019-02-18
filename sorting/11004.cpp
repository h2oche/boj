#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX_N 5000000
using namespace std;

int n,m;
int buf[MAX_N] = {0,};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for(int i = 0 ; i < n; i++) cin >> buf[i];
  sort(buf, buf+n);
  cout << buf[m-1];
  return 0;
}
