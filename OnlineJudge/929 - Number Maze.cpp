#include <bits/stdc++.h>

using namespace std;

struct Point {
    int cost, x, y;
    
    bool operator>(const Point& other) const {
        return cost > other.cost;
    }
};

int vec[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int m[1000][1000];

int N, M;

void exec() {
    
    int minCost[N][M];
    for(int i = 0;i < N;i++) {
        for(int j = 0; j < M; j++) {
            minCost[i][j] = 2147483647;
        }
    }
    
    minCost[0][0] = m[0][0];

    priority_queue<Point, vector<Point>, greater<Point>> pq;
    pq.push({m[0][0], 0, 0});

    while (!pq.empty()) {
        Point p = pq.top();
        int x = p.x, y = p.y;
        pq.pop();

        if (x == N - 1 && y == M - 1) {
            cout << p.cost <<"\n";
        }

        for (int i = 0;i<4;i++) {
            int x2 = x + vec[i][0];
            int y2 = y + vec[i][1];
            if (x2 >= 0 && x2 < N && y2 >= 0 && y2 < M) {
                int c2 = p.cost + m[x2][y2];
                if (c2 < minCost[x2][y2]) {
                    minCost[x2][y2] = c2;
                    pq.push({c2, x2, y2});
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> N >> M;
        for(int i = 0;i<N;i++) {
            for(int j = 0;j<M;j++) {
                cin >> m[i][j];
            }
        }
        exec();
    }
}
