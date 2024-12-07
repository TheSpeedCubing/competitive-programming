#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y, z, step;
};

int vec[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};

int L, R, C;

bool validate(int x, int y, int z) {
    return x >= 0 && x < L && y >= 0 && y < R && z >= 0 && z < C;
}

int main() {
    while(cin >> L >> R >> C && L) {
        cin.ignore(); // \n
        
        char q[31][31][31] = {};
        bool visited[31][31][31] = {};
        
        
        int sX, sY, sZ;
        
        for(int i = 0;i<L;i++) {
            for(int j = 0;j<R;j++) { 
                for(int k = 0;k<C;k++) {
                    cin >> q[i][j][k];
                    if(q[i][j][k] == 'S') {
                        sX = i;
                        sY = j;
                        sZ = k;
                    }
                }
                cin.ignore();
            }
            cin.ignore();
        }
        
        queue<Point> que;
        que.push({sX,sY,sZ,0});
        visited[sX][sY][sZ] = true;
        
        int f = -1;
        int x2, y2, z2;
        
        while(!que.empty()) {
            Point p = que.front();
            que.pop();
            if(q[p.x][p.y][p.z] == 'E') {
                f = p.step;
                break;
            }
            
            for(int i = 0;i<6;i++) {
                x2 = p.x + vec[i][0];
                y2 = p.y + vec[i][1];
                z2 = p.z + vec[i][2];
                if(validate(x2,y2,z2) && q[x2][y2][z2] != '#' && !visited[x2][y2][z2]) {
                    visited[x2][y2][z2] = true;
                    que.push({x2,y2,z2,p.step+1});
                }
            }
        }
        
        if(f == -1) {
            cout << "Trapped!\n";
        } else {
            cout << "Escaped in " << f << " minute(s).\n";
        }
    }
}
