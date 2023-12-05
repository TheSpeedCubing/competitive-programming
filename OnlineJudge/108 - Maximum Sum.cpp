// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

int main() {
  int size;
  while (cin >> size && size) {

    int sum[size][size];
    
    
    for (int r = 0; r < size; r++) {
    	memset(sum[r], 0, size * sizeof(int));
    }

    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
      	int in;
        cin >> in;
        for (int i = r; i < size; i++)
          sum[i][c] += in;
      }
    }

    int maxS = 0;
    for (int i = size - 1; i >= 0; i--) {
      for (int j = -1; j < i; j++) {
      	
        int n[size];
        for (int k = 0; k < size; k++)
          n[k] = j == -1 ? sum[i][k] : (sum[i][k] - sum[j][k]);

        int max = n[0], dp = max;
        for (int m = 1; m < size; m++) {
          if (dp > 0) {
            dp += n[m];
          } else {
            dp = n[m];
          }
          if (dp > max) {
            max = dp;
          }
        }
        
        if(maxS < max)
          maxS = max;
      }
    }
    
    cout << maxS <<"\n";
  }
}
