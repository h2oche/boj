#include <iostream>
#include <set>
#include <vector>
using namespace std;

void print_permu(int n, int depth, set<int> used, vector<int> permu) {
  if(depth == 0) {
    for(int v : permu)
      cout << v << ' ';
    cout << '\n';
    return;
  }

  for(int i = 1 ; i <=n ; i++) {
    if(used.count(i) != 0) continue;
    set<int> copy_used = used;
    copy_used.insert(i);

    vector<int> copy_permu = permu;
    copy_permu.push_back(i);

    print_permu(n, depth - 1, copy_used, copy_permu);
  }
}

int main(void) {
  int n, m; cin >> n >> m;
  print_permu(n, m, set<int>(), vector<int>());
  return 0;
}