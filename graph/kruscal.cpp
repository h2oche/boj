//http://weeklyps.com/entry/%ED%81%AC%EB%A3%A8%EC%8A%A4%EC%B9%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Kruskals-algorithm

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Edge {
    int v1, v2, cost;
    Edge(){}
    Edge(int v1, int v2, int cost) : v1(v1), v2(v2), cost(cost) {}
    bool operator<(const Edge& v) const {
        return cost < v.cost;
    }
    friend ostream& operator<<(ostream& cout, const Edge& e);
};

ostream& operator<<(ostream& ost, const Edge& e) {
    ost << e.v1 << " <--> " << e.v2 << "(" << e.cost <<")\n";
    return ost;
}

struct UnionFindSet {
    vector<int> group;
    vector<int> parent;
    vector<int> group_size;
    void init(int n) {
        for(int i = 0 ; i <= n ; i ++) {
            group.push_back(i);
            parent.push_back(i);
            group_size.push_back(1);
        }
    }
    int get_root(int v) {
        if(parent[v] == v) return v;
        return parent[v] = get_root(parent[v]);
    }
    bool is_same_group(int v1, int v2) {
        return get_root(v1) == get_root(v2);
    }
    void merge(int v1, int v2){
        if(is_same_group(v1, v2)) return;

        int v1_root = get_root(v1);
        int v2_root = get_root(v2);

        if(group_size[v1_root] < group_size[v2_root])
            swap(v1, v2);
        
        parent[get_root(v2)] = v1;
        group_size[v1_root] += group_size[v2_root];
    }
};

vector<Edge> adjs;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    UnionFindSet u;
    u.init(n);

    for(int i = 0 ; i < n ; i += 1) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        adjs.push_back(Edge(v1,v2,c));
    }

    sort(adjs.begin(), adjs.end());

    vector<Edge> answer;
    int cost = 0;
    for(auto e : adjs) {
        if(u.is_same_group(e.v1, e.v2)) continue;

        answer.push_back(e);
        u.merge(e.v1, e.v2);    
        cost += e.cost;
    }

    cout << "cost : " << cost << '\n';
    for(auto e : answer)
        cout << e;

    return 0;
}