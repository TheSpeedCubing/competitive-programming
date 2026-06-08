#include <bits/stdc++.h>

using namespace std;

int vec[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};

int main() {
    int n, m;
    
    int t = 0;
    while (cin >> n >> m && n && m) {
        if(t++) cout << "\n"; 
        char arr[n][m];
        int cnt[n][m] = {};
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                cin >> arr[i][j];
                if(arr[i][j] != '*') {
                    continue;
                }
                for(int k = 0;k<8;k++) {
                    int ii = i + vec[k][0];
                    int jj = j + vec[k][1];
                    if(ii < 0 || ii >= n || jj < 0 || jj >= m) {
                        continue;
                    }
                    cnt[ii][jj]++;
                }
            }
        }
        
        cout << "Field #" << t << ":\n";
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(arr[i][j] == '*') {
                    cout << '*';
                } else {
                    cout << cnt[i][j];
                }
            }
            cout << "\n";
        }
        
        
    }
}