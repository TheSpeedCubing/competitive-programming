#include <bits/stdc++.h>

using namespace std;

int n[8][8],
    visited[8][8],
    vec[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1}},
    v,
    cnt = 0;
    
bool validate(int x, int y) {
  return x >= 0 && y >= 0 && x < 8 && y < 8;
}

void search(int x, int y) {
    int i = 8;
  while(i--) {
    int dx = vec[i][0], dy = vec[i][1];
    if (validate(x + dx, y + dy) && n[x + dx][y + dy] == v) {
      int nx = x - dx, ny = y - dy;
      while (validate(nx, ny) && n[nx][ny] != v) {
        if (n[nx][ny] == 0) {
          if (!visited[nx][ny]) {
            cnt++;
            visited[nx][ny] = 1;
          }
          break;
        }
        nx -= dx;
        ny -= dy;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cnt = 0;
    
    int in, total = 0;

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        cin >> in;
        visited[i][j] = 0;
        n[i][j] = in;
        total += (in ? 1 : 0);
      }
    }
    
    v = total % 2 + 1;

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (n[i][j] == 3 - v) {
          search(i, j);
        }
      }
    }
    cout << (v == 2 ? "W " : "B ") << cnt << "\n";
  }
}