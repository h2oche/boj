//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
vector<string> map;
struct coord{
    int x,y,cost;
    coord(){}
    coord(int x, int y, int cost): x(x), y(y), cost(cost){};
};
int main(void)
{
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i += 1) {
        map.push_back("");
        for(int j = 0 ; j < m ; j += 1) {
            char c;
            cin >> c;
            if(c == '\n') break;
            map[i].push_back(c);
        }
    }

    int min_cost = INT_MAX;
    vector<coord> q;
    q.push_back(coord(0,0,1));
    while(!q.empty()) {
        coord check = q.back();
        q.pop_back();
        if(check.y + 1 == n && check.x + 1 == m)
            if(min_cost > check.cost) min_cost = check.cost;
        if(map[check.y][check.x] == '0') continue;
        map[check.y][check.x] = '0';

        vector<coord> items;
        if(check.x - 1>=0) items.push_back({check.x-1,check.y,check.cost+1});
        if(check.x + 1< m) items.push_back({check.x+1,check.y,check.cost+1});
        if(check.y - 1>=0) items.push_back({check.x,check.y-1,check.cost+1});
        if(check.y + 1< n) items.push_back({check.x,check.y+1,check.cost+1});

        for(auto c : items)
            if(map[c.y][c.x] == '1') q.insert(q.begin(),c);
    }
    cout << min_cost;
    return 0;
}