#include <vector>
#include <queue>
#include <string>
#include <stdio.h>

using namespace std;

struct coord{
    int x, y, cost, remain;
    bool is_breaked;
    coord() {}
    coord(int x, int y, int cost, int remain, bool is_breaked): x(x), y(y), cost(cost), remain(remain), is_breaked(is_breaked){}
};

vector<string> map;
char buffer[1001];
queue<coord> q;
bool visited[1001][1001][2] = {false,};

int main(void)
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    for(int i = 0 ; i < n ; i ++) {
        scanf("%s\n", buffer);
        map.push_back(string(buffer));
    }

    int ans = -1;
    q.push(coord(0,0,1,1,false));
    visited[0][0][0] = true;
    while(!q.empty()) {
        coord check = q.front();
        q.pop();

        if(!check.is_breaked && map[check.y][check.x] == '1') continue;
        if(check.x + 1 == m && check.y + 1 == n) {
            ans = check.cost;
            break;
        }
        
        vector<coord> candid;
        int cost = check.cost + 1;
        if(check.x - 1 >= 0) candid.push_back(coord(check.x-1,check.y,cost,check.remain,false));
        if(check.x + 1 < m) candid.push_back(coord(check.x+1,check.y,cost,check.remain,false));
        if(check.y - 1 >= 0) candid.push_back(coord(check.x,check.y-1,cost,check.remain,false));
        if(check.y + 1 < n) candid.push_back(coord(check.x,check.y+1,cost,check.remain,false));

        for(auto c : candid) {
            if(visited[c.y][c.x][c.is_breaked == false ? 0 : 1]) continue;
            if(map[c.y][c.x] == '0')
                q.push(c);
            else if(map[c.y][c.x] == '1' && check.remain > 0)
                q.push(coord(c.x, c.y, c.cost, 0, true));
            visited[c.y][c.x][c.is_breaked == false ? 0 : 1] = true;
        }
    }

    printf("%d\n", ans);
    return 0;
}