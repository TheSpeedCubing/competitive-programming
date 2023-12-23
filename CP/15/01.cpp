#include <bits/stdc++.h>

using namespace std;

int d[5][2] = {{0,1},{0,-1},{1,0},{-1,0},{0,0}};

int main() {
  string s;
  int flag = 0;
  while (getline(cin, s)) {
    if (flag++)
      cout << "\n";

    int n[3][3] = {
      0
    };

    for (int i = 0; i < s.length(); i++) {
      if (isalpha(s[i]) && !isdigit(s[i + 1])) {
        i++;
        s = s.substr(0, i) + "1" + s.substr(i);
      }
    }

    char c;
    int r;
    stringstream stream(s);
    while (stream >> c >> r) {
      while (r--) {
        int i = c - 'a';
        for (int j = 0; j < 5; j++) {
          int xx = i / 3 - d[j][0], yy = i % 3 - d[j][1];
          if (xx > -1 && yy > -1 && xx < 3 && yy < 3) {
            int o = n[xx][yy];
            n[xx][yy] = o == 9 ? 0 : o + 1;
          }
        }
      }
    }
    for (int i = 0; i < 9; i++)
       cout << n[i/3][i%3] << (i%3 == 2 ? "\n" : " ");
  }
}