#include <bits/stdc++.h>

using namespace std;

/*
 * 
 */

bool eq(vector<int> a, vector<int> b) {
    for(int i = 0;i<a.size();i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int h, w;
    int k = 4;
    cin >> h >> w;

    vector<int> blocks[4][4] = {};
    for(int i = 0;i<4;i++) {
        for(int j = 0;j<4;j++) {
            blocks[i][j] = vector<int>(0);
        }
    }

    for(int k = 0;k<4;k++) {
        for(int i = 0;i<h;i++) {
            for(int j = 0;j<w;j++) {
                int z;
                cin >> z;
                if(i == 0) {
                    blocks[k][2].push_back(z);
                }
                if(i == h-1) {
                    blocks[k][3].push_back(z);
                }
                if(j == 0) {
                    blocks[k][0].push_back(z);
                }
                if(j == w - 1) {
                    blocks[k][1].push_back(z);
                }
            }
        }
    }
//    for(int i = 0;i<4;i++) {
//        for(int j = 0;j<4;j++) {
//            cout << blocks[i][j].size() << "\n";
//            for(int k = 0;k<blocks[i][j].size();k++) {
//                cout << blocks[i][j][k] << " ";
//            }
//            cout << "\n";
//        }
//            cout << "\n";
//    }
//    cout << "OK\n";
    int f = 6;
    for(int i = 0;i<4;i++) {
        for(int j = 0;j<4;j++) {
            if(j == i) {
                continue;
            }
            for(int k = 0;k<4;k++) {
                if(k == i || k == j) {
                    continue;
                }
                int l = f - i - j - k;
                    int z = 0;
                    if(eq(blocks[i][3] , blocks[k][2])) {
                        z++;
                    }
                    if(eq(blocks[j][3] ,blocks[l][2])) {
                        z++;
                    }
                    if(eq(blocks[i][0] ,blocks[j][1])) {
                        z++;

                    }
                    if(eq(blocks[k][0] , blocks[l][1])) {
                        z++;
                    }
//                    if(z == 4) {
//                    cout << i << " " << j << " " << k << " " << l << "\n";
//                    for(int a = 0;a<4;a++) {
//                        for(int b = 0;b< blocks[i][a].size();b++) {
//                            cout << blocks[i][a][b];
//                        }
//                        cout << "\n";
//                    }
//                    for(int a = 0;a<4;a++) {
//                        for(int b = 0;b< blocks[j][a].size();b++) {
//                            cout << blocks[j][a][b];
//                        }
//                        cout << "\n";
//                    }
//                    for(int a = 0;a<4;a++) {
//                        for(int b = 0;b< blocks[k][a].size();b++) {
//                            cout << blocks[k][a][b];
//                        }
//                        cout << "\n";
//                    }
//                    for(int a = 0;a<4;a++) {
//                        for(int b = 0;b< blocks[l][a].size();b++) {
//                            cout << blocks[l][a][b];
//                        }
//                        cout << "\n";
                    if(z == 4) {
                    char w[4] = {'A','B','C','D'};
                    cout << w[j] << w[i] << '\n';
                    cout << w[l] << w[k] << '\n';
                    }
            }
        }
    }
}