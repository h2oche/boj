#include <vector>
#include <iostream>
using namespace std;

vector<int> pi, T;
string tar, p;

void getPi(void) {
  int i = 1; int j = 0;
  pi.push_back(0);

  while(i < p.length()) {
    if(p[i] == p[j]) {
      pi.push_back(j + 1);
      i++; j++;
    } else {
      if(j == 0) {
        pi.push_back(0);
        i++;
      } else {
        j = pi[j-1];
      }
    }
  }
}

void getT(void) {
  int i = 1; int j = 0;
  T.push_back(-1);

  while(i < p.length()) {
    if(pi[i-1] > 0 && p[pi[i-1]] != p[i]) {
      T.push_back(pi[i-1]);
    }
    else {
      if(p[i] == p[0])
        T.push_back(-1);
      else
        T.push_back(0);
    }

    i++;
  }

  T.push_back(pi.back());
}

int main(void)
{
  getline(cin, tar);
  getline(cin, p);

  getPi();
  getT();

  // for(int num : pi) cout << num << endl;
  for(int num : T) cout << num << endl;
  vector<int> pos;

  int k = 0 ; int j = 0;
  while(k < tar.length()) {
    if(tar[k] == p[j]) {
      k++; j++;
      if(j == p.length()) {
        pos.push_back(k - j + 1);
        j = T[j];
      }
    } else {
      j = T[j];
      if(j < 0) {
        j = 0;
        k++;
      }
    }
  }

  // cout << pos.size() << '\n';
  // for(int num : pos) cout << num << ' ';

  return 0;
}