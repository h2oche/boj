//https://www.acmicpc.net/problem/1647
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
struct edge {
    int v1, v2, cost;
    edge(){}
    edge(int v1, int v2, int cost): v1(v1), v2(v2), cost(cost){}
    bool operator<(const edge& e) const {
        return cost < e.cost;
    }
};
struct union_find_set{
    vector<int> group;
    vector<vector<int>> group_members;
    vector<bool> is_root;
    int root_count;
    
    void init(int n) {
        root_count = n;
        for(int i = 0 ; i <= n ; i += 1) {
            group.push_back(i);
            group_members.push_back({i});
            is_root.push_back(true);
        }
        is_root[0] = false;
    }
    bool is_same_group(int v1, int v2){
        return group[v1] == group[v2];
    }
    void merge(int v1, int v2) {
        if(is_same_group(v1, v2)) return;
        if(group_members[group[v1]].size() < group_members[group[v2]].size()) swap(v1, v2);
        int old_group = group[v2];
        int root_change_count=0;
        for(auto v : group_members[old_group]) {
            group[v] = group[v1];
            group_members[v1].push_back(v);
            if(is_root[v]) root_change_count++;
            is_root[v] = false;
        }
        group_members[old_group].clear();
        root_count -= root_change_count;
    }
};

vector<edge> adjs;
union_find_set u;
int main(void)
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    for(int i = 0 ; i < m ; i ++) {
        int v1, v2, cost;
        scanf("%d %d %d\n", &v1, &v2, &cost);
        if(v1 >= v2) swap(v1, v2);
        adjs.push_back(edge(v1, v2, cost));
    }
    sort(adjs.begin(), adjs.end());
    u.init(n);

    int cost=0;
    for(auto e : adjs) {
        if(u.is_same_group(e.v1, e.v2)) continue;
        if(u.root_count <= 2) break;
        u.merge(e.v1, e.v2);
        cost += e.cost;
    }
    printf("%d\n", cost);

    return 0;
}