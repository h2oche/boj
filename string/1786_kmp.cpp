//https://www.acmicpc.net/problem/1786

#include <string>
#include <vector>
// #include <cstdio>
#include <iostream>
using namespace std;

string target, needle;
vector<int> T, S;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  getline(cin, target);
  getline(cin, needle);
  // cout << target << endl << needle << endl;

  S.push_back(0);
  int k = 1; int j = 0;
  while(k < needle.length()) {
    if(needle[k] == needle[j]) {
      S.push_back(j+1);
      k++; j++;
    } else {
      if(j == 0) {
        S.push_back(0);
        k++;
      } else {
        j = S[j-1];
      }
    }
  }

  // for(int num : S) cout << num << endl;

  int count = 0;
  vector<int> pos;

  k = 0; j = 0;
  while(k < target.length()) {
    if(target[k] == needle[j]) {
      k++; j++;
      if(j == needle.length()) {
        count++;
        pos.push_back(k - j + 1);
        j = S[j-1];
      }
    } else {
      if(j == 0) {
        k++;
      } else {
        j = S[j-1];
      }
    }
  }

  cout << count << '\n';
  for(int i = 0 ; i < pos.size() ; i += 1) {
    cout << pos[i] << " ";
  }

  return 0;
}