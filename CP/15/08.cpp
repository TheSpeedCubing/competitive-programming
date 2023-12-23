#include <bits/stdc++.h>

using namespace std;

struct Pos {
  int x;
  int y;
  int step;
  Pos(int x, int y, int step): x(x), y(y), step(step) {}
};

int destX, destY, found = 0 ,visited[8][8];

queue <Pos> q;

void canBFS(int x, int y, int step) {
  if (x > -1 && y > -1 && x < 8 && y < 8 && !found && !visited[x][y]) {
    visited[x][y] = 1;
    if (x == destX && y == destY) {
      found = step + 1;
      return;
    }
    q.push(Pos(x, y, step + 1));
  }
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {

      found = 0;

      while (!q.empty())
        q.pop();

      for (int i = 0; i < 64; i++)
          visited[i/8][i%8] = 0;

      int x = s1[0] - 'a', y = s1[1] - '0' - 1;
      destX = s2[0] - 'a';
      destY = s2[1] - '0' - 1;

      if (!(x == destX && y == destY)) {

          Pos start(x, y, 0);
          q.push(start);
          while (!q.empty()) {
            Pos p = q.front();
            int x = p.x, y = p.y, step = p.step;
            canBFS(x - 2, y + 1, step);
            canBFS(x - 2, y - 1, step);
            canBFS(x - 1, y + 2, step);
            canBFS(x + 1, y + 2, step);
            canBFS(x + 2, y + 1, step);
            canBFS(x + 2, y - 1, step);
            canBFS(x - 1, y - 2, step);
            canBFS(x + 1, y - 2, step);
            if (found)
              break;
            q.pop();
          }
        }

        cout << "To get from " << s1 << " to " << s2 << " takes " << found << " knight moves.\n";
      }
    }