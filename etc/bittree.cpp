#include <iostream>
#include <vector>
using namespace std;

vector<long long> a;
vector<long long> tree;
int n, m, k;

long long sum(int index) {
  int result = 0;
  while(index > 0) {
    result += tree[index];
    index -= index & (-index);
  }
  return result;
}

void update(int index, long long diff) {
  while(index < n) {
    tree[index] += diff;
    index += index & (-index);
  }
}

int main(void)
{
  cin >> n >> m >> k;
  tree = vector<long long>(n + 1);
  a.push_back(0);
  for(int i = 1 ; i <= n ; i += 1) {
    int num; cin >> num;
    a.push_back(num);
    update(i, a[i]);
  }

  for(int i = 0 ; i < m + k ; i += 1) {
    int op, p1, p2;
    cin >> op >> p1 >> p2;
    switch(op) {
    case 1:
      update(p1, p2 - a[p1]);
      break;
    case 2:
      cout << sum(p2) - sum(p1) << '\n';
    break;
    }
  }

  return 0;
}