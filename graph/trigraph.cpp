//https://www.acmicpc.net/problem/4883

#include <iostream>
#include <climits>
#define N 100000

using namespace std;

int graph[N][3] = {0,};
long long dist[N][3] = {0,};

int main(void)
{
    int number = 1;
    while(true) {
        int n;
        cin >> n;

        if(n==0) break;

        for(int i = 0 ; i < n ; i += 1)
            scanf("%d %d %d\n", &graph[i][0], &graph[i][1], &graph[i][2]);

        dist[0][0] = LONG_MAX;
        dist[0][1] = graph[0][1];
        dist[0][2] = graph[0][1] + graph[0][2];

        int zero;
        cin >> zero;

        for(int i = 1 ; i < n ; i += 1) {
            dist[i][0] = min(dist[i-1][0], dist[i-1][1]) + graph[i][0];
            long long min1_1 = min(dist[i][0], dist[i-1][0]);
            long long min1_2 = min(dist[i-1][1], dist[i-1][2]);
            dist[i][1] = min(min1_1, min1_2) + graph[i][1];
            long long min2 = min(dist[i-1][1], dist[i-1][2]);
            dist[i][2] = min((long long)min2, dist[i][1]) + graph[i][2];
        }

        cout << number << ". " << dist[n-1][1] << endl;
        number++;
    }
    

    return 0;
}