//http://weeklyps.com/entry/%EC%9C%A0%EB%8B%88%EC%98%A8-%ED%8C%8C%EC%9D%B8%EB%93%9C-Unionfind
#include <vector>

using namespace std;

struct union_find {
    vector<int> group;
    int n;
    void init(int n) {
        n = n;
        group.push_back(0);
        for(int i = 1 ; i <= n ; i += 1) {
            group.push_back(i);
        }
    }
    bool is_same(int v1, int v2) {
        return group[v1] == group[v2];
    }
    //O(n), n개 병합에는 O(n^2)
    void merge(int v1, int v2) {
        int remove_group = group[v2];
        for(int i = 1 ; i <= n ; i += 1) {
            if(group[i] == remove_group)
                group[i] = group[v1];
        }
    }
};

struct union_find_opt1 {
    vector<int> group;
    vector<vector<int>> members;
    int n;

    void init(int n) {
        n = n;
        group.push_back(0);
        members.push_back({0});
        for(int i = 1 ; i <= n ; i += 1) {
            group.push_back(i);
            members.push_back({i});
        }
    }
    bool is_same(int v1, int v2) {
        return group[v1] == group[v2];
    }
    //O(n), n개 병합에는 O(nlogn)
    void merge(int v1, int v2) {
        if(members[v1].size() < members[v2].size())
            swap(v1, v2);

        int remove_group = group[v2];
        for(auto m : members[remove_group]) {
            group[m] = group[v1];
            members[v1].push_back(m);
        }
        members[remove_group].clear();
    }
};

struct union_find_opt2 {
    vector<int> group;
    vector<int> parent;
    vector<int> tree_size;
    int n;
    
    void init(int n) {
        n = n;
        group.push_back(0);
        parent.push_back(0);
        tree_size.push_back(0);

        for(int i = 1 ; i <= n ; i += 1) {
            group.push_back(i);
            parent.push_back(i);
            tree_size.push_back(1);
        }
    }

    bool is_same(int v1, int v2) {
        return get_root(v1) == get_root(v2);
    } 

    int get_root(int v) {
        if(get_root(v) == v) return v;
        return parent[v] = get_root(parent[v]);
    }

    // < O(logn), n개 병합에는 O(n) < < O(nlogn)
    void merge(int v1, int v2) {
        int v1_root = get_root(v1);
        int v2_root = get_root(v2);
        if(v1 == v2) return;

        if(tree_size[v1_root] < tree_size[v2_root])
            swap(v1, v2);

        parent[v2] = v1;
    }
};