#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

string n,m;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  int min_val = 100;
  for(int i = 0 ; i <= m.size() - n.size() ; i++) {
    int cnt = 0;
    for(int j = 0; j < n.size(); j ++)
      if(n[j] != m[i+j])
        cnt++;
    min_val = min(min_val, cnt);
  }

  cout << min_val;
  
  return 0;
}
