//https://www.acmicpc.net/problem/1922
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <functional>

using namespace std;

struct Edge {
    int v1, v2, cost;
    Edge(){}
    Edge(int v1, int v2, int cost) : v1(v1), v2(v2), cost(cost) {}
    bool operator<(const Edge& v) const {
        return cost < v.cost;
    }
};

struct UnionFindSet {
    vector<int> parent;
    void init(int n) {
        for(int i = 0 ; i <= n ; i ++) {
            parent.push_back(i);
        }
    }
    int get_root(int v) {
        if(parent[v] == v) return v;
        parent[v] = get_root(parent[v]);
        return parent[v];
    }
    bool is_same_group(int v1, int v2) {
        return get_root(v1) == get_root(v2);
    }
    void merge(int v1, int v2){
        if(is_same_group(v1, v2)) return;
        parent[get_root(parent[v2])] = v1;
    }
};

vector<Edge> adjs;

int main(void)
{
    int n, m;
    scanf("%d\n%d\n", &n, &m);

    UnionFindSet u;
    u.init(n);

    for(int i = 0 ; i < m ; i += 1) {
        int v1, v2, c;
        scanf("%d %d %d\n", &v1, &v2, &c);
        if(v1 >= v2) swap(v1, v2);
        adjs.push_back(Edge(v1,v2,c));
    }

    sort(adjs.begin(), adjs.end());

    int cost = 0;

    for(auto e : adjs) {
        if(u.is_same_group(e.v1, e.v2)) continue;
        u.merge(e.v1, e.v2);    
        cost += e.cost;
    }

    printf("%d\n", cost);;
    return 0;
}