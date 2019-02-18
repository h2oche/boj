#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int n,m;
vector<int> A, B, C;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  A = vector<int>(n);
  B = vector<int>(m);
  C = vector<int>(n+m);
  for(int i = 0 ; i < n ; i++) cin >> A[i];
  for(int i = 0 ; i < m ; i++) cin >> B[i];

  int a = 0, b = 0, c = 0;
  for(int c = 0 ; c < n + m ;) {
    if(a == n) C[c++] = B[b++];
    else if(b == m) C[c++] = A[a++];
    else C[c++] = A[a] < B[b] ? A[a++] : B[b++];
  }

  for(int i = 0 ; i < n + m ; i++)
    cout << C[i] << ' ';
  
  return 0;
}
