#include <iostream>
#include <vector>
using namespace std;

struct union_find_set {
	int n;
	vector<int> parent;

	void init(int _n) {
		int n = _n;
		for(int i = 0 ; i <= n ; i++)
			parent.push_back(i);
	}

	int get_root(int a) {
		if(parent[a] == a) return a;
		return parent[a] = get_root(parent[a]);
	}

	void merge(int a, int b) {
		parent[get_root(b)] = get_root(a);
	}

	bool is_same_group(int a, int b) {
		return get_root(a) == get_root(b);
	}
};

union_find_set s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m; cin >> n >> m;
	s.init(n);

	for(int i = 0 ; i < m ; i++) {
		int op, a, b; cin >> op >> a >> b;
		if(op == 0) {
			s.merge(a, b);
		} else {
			cout << (s.is_same_group(a, b) ? "yes" : "no") << '\n';
		}
	}
	return 0;
}