#include <iostream>

using namespace std;
int main() {
    int T,M,N,Q;
    cin >> T;
    
    while(T--) {
        cin >> M >> N >> Q;
        cout << M <<" "<<N<<" "<<Q <<"\n";
        char map[M][N];
        for(int i = 0;i<M;i++) {
            for(int j = 0;j<N;j++) {
                cin >> map[i][j];
            }
        }
        
        while(Q--) {
            int r,c;
            cin >> r >> c;
            char thisOne = map[r][c];
            
            int size = 0;
            bool valid = true;
            while(valid) {
                size++;
                int r1 = r - size, c1 = c - size;
                if(r1 < 0 || r1 + size*2 >= M || c1 < 0 || c1 + size*2 >= N) {
                    break;
                }
                
                for(int i = 0;i<=size*2;i++) {
                    if(thisOne != map[r1][c1+i] || 
                       thisOne != map[r1+i][c1] || 
                       thisOne != map[r1+i][c1 + size*2] ||
                       thisOne != map[r1+size*2][c1 + i]) {
                        valid = false;
                        break;
                    }
                }
            }
            cout << size*2-1 <<"\n";
        }
    }
}
