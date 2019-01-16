#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
    int x, y;
};
bool cmp(const Point &u, const Point &v) {
    return u.x < v.x;
}
int dist(Point &p1, Point &p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int main() {
    int n;
    scanf("%d",&n);
    vector<Point> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    sort(a.begin(), a.end(), cmp);
    vector<Point> candidate = {a[0], a[1]};
    int ans = dist(a[0], a[1]);
    for (int i=2; i<n; i++) {
        Point now = a[i];
        for (auto it = candidate.begin(); it!=candidate.end(); ) {
            auto p = *it;
            int x = now.x - p.x;
            if (x*x > ans) {
                it = candidate.erase(it);
            } else {
                int d = dist(now, p);
                if (d < ans) {
                    ans = d;
                }
                it++;
            }
        }
        candidate.push_back(now);
    }
    printf("%d\n",ans);
    return 0;
}