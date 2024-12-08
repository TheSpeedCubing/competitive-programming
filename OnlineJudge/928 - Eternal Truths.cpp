#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y, step, seq;
};
        
int vec[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};


int main() {
    int t;
    cin >> t;
    while(t--) {
        int R, C;
        cin >> R >> C;
        cin.ignore();
        
        char m[R][C] = {};
        
        int sX, sY;
        for(int i = 0;i<R;i++) {
            for(int j = 0;j<C;j++) {
                cin >> m[i][j];
                if(m[i][j] == 'S') {
                    sX = i;
                    sY = j;
                }
            }
            cin.ignore();
        }
        
        
        bool visited[R][C][4] = {};
        
        queue<Point> que;
        
        que.push({sX,sY,0,0});
        visited[sX][sY][1] = true;
        
        int f = -1;
        while(!que.empty()) {
            Point p = que.front();
            que.pop();
            if(m[p.x][p.y] == 'E') {
                f = p.step;
                break;
            }
            int seq = p.seq;
            seq++;
            if(seq == 4) {
                seq = 1;
            }
            for (int i = 0;i<4;i++) {
                int x2 = p.x + vec[i][0] * seq;
                int y2 = p.y + vec[i][1] * seq;
                
                if(visited[x2][y2][seq]) {
                    continue;
                }
                if(x2 < 0 || x2 >= R || y2 < 0 || y2 >= C) {
                    continue;
                }
                
                bool f = true;
                int xx2 = p.x;
                int yy2 = p.y;
                for(int j = 0;j<seq;j++) {
                    xx2 += vec[i][0];
                    yy2 += vec[i][1];
                    if(m[xx2][yy2] == '#') {
                        f = false;
                        break;
                    }
                }
                    
                if(!f) continue;
                
                visited[x2][y2][seq] = true;
                que.push({x2,y2,p.step+1,seq});
            }
        }
        if(f == -1) {
            cout << "NO\n";
        } else cout << f <<"\n";
    }
}
