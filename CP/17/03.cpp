#include <bits/stdc++.h>

using namespace std;

int main() {
  int T,Q, flag = 0,m, n;
  cin >> T;
  while (T--) {
    if (flag++)
      cout << "\n";
      
    cin >> m >> n;

    int arr[32768], result[32768], reverse[32768], size = m * n, 
    i = 0;
    while(i<size)
      cin >> arr[i++];

    int turn = 0, x = 0, y = 0, x1 = 0, y1 = 0, x2 = n - 1, y2 = m - 1;
    
    i = 0;
    while(i < size) {
      result[i] = y * n + x;
      reverse[y * n + x] = i++;

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

    cin >> Q;
    i = 0;
    while(i<size) {
      int r = reverse[i] - Q;
      while (r >= size)
        r -= size;
      while (r < 0)
        r += size;
      printf("%3d%c", arr[result[r]],((++i) % n ? ' ' : '\n'));
    }
  }
}
