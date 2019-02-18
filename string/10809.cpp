#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define endl '\n'
using namespace std;

int buf[26] = {0,};
string str;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  memset(buf, -1, sizeof buf);

  cin >> str;
  for(int i = 0 ; i < str.size() ; i++) {
    int idx = str[i] - 'a';
    if(buf[idx] == -1) buf[idx] = i;
  }

  for(int i = 0 ; i < 26 ; i++)
    cout << buf[i] << ' ';
  
  return 0;
}
