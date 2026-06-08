#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        
        int arr[101][101] = {};
        
        for(int i = x1; i < x2; i++) {
            for(int j = y1; j < y2; j++) {
                arr[i][j]++;
            }
        }
        
        for(int i = x3; i < x4; i++) {
            for(int j = y3; j < y4; j++) {
                arr[i][j]++;
            }
        }
        
        int strong = 0;
        int weak = 0;
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                if(arr[i][j] == 2) {
                    strong++;
                }
                if(arr[i][j] == 1) {
                    weak++;
                }
            }
        }
        
        cout << "Night " << t << ": " << strong << " " << weak << " " << (10000 - strong - weak) << "\n";
    }
}