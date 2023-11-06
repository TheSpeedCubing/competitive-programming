#include <iostream>

using namespace std;

int main() {
    int n;
    while(cin >> n && n){
    int d[100][100], row = 0;

    for (; row < n; row++) {
        for (int j = 0; j <= row; j++) {
        	cin >> d[row][j];
        }
    }

    for (row = n - 2; row >= 0; row--) {
        for (int i = 0; i <= row; i++) {
            d[row][i] += max(d[row + 1][i], d[row + 1][i + 1]);
        }
    }

    cout <<d[0][0]<<"\n";
    }
}