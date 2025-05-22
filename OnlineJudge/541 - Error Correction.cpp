#include <iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    int m[n][n];
    
    int rowSum[n] = {};
    int colSum[n] = {};
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> m[i][j];
        if(m[i][j]) {
          rowSum[i] ++;
          colSum[j] ++;
        }
      }
    }
    
    bool corrupt = false;
    
    int x = -1, y = -1;
    for (int i = 0; i < n && !corrupt; i++) {
      if (rowSum[i] % 2 != 0) {
        if (x == -1) {
          x = i; 
        } else {
          corrupt = true;
        }
      }
      if (colSum[i] % 2 != 0) {
        if (y == -1) {
          y = i; 
        } else {
          corrupt = true;
        }
      }
    }
    
    if (corrupt) {
      cout <<"Corrupt\n";
    } else if (x == -1) {
      cout << "OK\n";
    } else {
      cout <<"Change bit (" << (x+1) << "," << (y+1) << ")\n";
    }
  }
}
