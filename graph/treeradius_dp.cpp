//https://www.acmicpc.net/problem/1967

#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>

#define N 10000

using namespace std;

vector<pair<int, int>> adjs[N+1];
int parent[N+1] = {0,};
int parent_weight[N+1] = {0,};
int dist[N+1] = {0,};
int parent_dist[N+1] = {0,};

int main(void)
{
    int n;
    cin >> n;

    for(int i = 0 ; i < n - 1 ; i += 1) {
        int p, c, w;
        scanf("%d %d %d\n", &p, &c, &w);
        adjs[p].push_back(make_pair(c,w));
        parent[c] = p;
        parent_weight[c] = w;
    }

    for(int i = N ; i > 0 ; i -= 1) {
        int child_dist_max = 0;
        for(auto edge : adjs[i])
            child_dist_max = max(child_dist_max, dist[edge.first] + edge.second);
        dist[i] = child_dist_max;
    }

    

    for(int i = 2 ; i <= N ; i += 1) {
        auto edges = adjs[parent[i]];
        int parent_dist_max = parent_dist[parent[i]] + parent_weight[i];
        for(auto edge : edges) {
            if(edge.first == i) continue;
            parent_dist_max = max(parent_dist_max, parent_weight[i] + edge.second + dist[edge.first]);
        }
        parent_dist[i] = parent_dist_max;
    }

    int ans = 0;
    for(int i = 1 ; i <= n ; i += 1) {
        int max_dist = max(dist[i], parent_dist[i]);
        ans = max(ans, max_dist);
    }

    cout << ans;
    
    return 0;
}