#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, n, d;
  cin >> T;
  int flag = 0;
  while (T--) {
    if (flag++)
      cout << "\n";
    cin >> n >> d;
    
    int arr[100][100] = {0}
        , turn = 0
        , x = 0, y = 0, x1 = 0, y1 = 0, x2 = n - 1, y2 = n - 1;
    for (int i = 1;i <= n * n;i++) {
      d == 1 ? arr[y][x] = i : arr[x][y] = i;
      
      turn ? (turn == 1 ? y++ : (turn == 2 ? x-- : y--)) : x++;

      if (x == x2) {
        if (y == y1 && turn == 0) {
        	turn++;
          y1++;
        }
        if (y == y2 && turn == 1) {
        	turn++;
          x2--;
        }
      }
      if (x == x1) {
        if (y == y2 && turn == 2) {
        	turn++;
          y2--;
        }
        if (y == y1 && turn == 3) {
          turn = 0;
          x1++;
        }
      }
    }
    
    for (int i = 0; i < n * n; i++) {
        printf("%5d", arr[i/n][i%n]);
        cout << (i%n == n - 1 ? "\n" : " ");
    }
  }
}