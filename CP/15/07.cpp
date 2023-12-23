#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, flag = 0;
  while (cin >> t && t) {
    if (flag++)
      cout << "\n";

    string r[1024];
    for (int i = 0; i < 1024; i++)
      for (int j = 0; j < 1024; j++)
        r[i] += " ";
    r[0][0] = '*';
    r[1][0] = '*';
    r[1][1] = '*';

    int size = (abs(t) - 1) % 10;
    int h = 2, w = 2;
    while (size--) {
      for (int j = 0; j < h; j++) {
        for (int k = 0; k < w; k++) {
          r[j + h][k] = r[j][k];
          r[j + h][k + w] = r[j][k];
        }
      }
      h *= 2;
      w *= 2;
    }

    for (int i = (t > 0 ? 0 : h - 1); i != (t > 0 ? h : -1); i += abs(t) / t) {
      bool f = 0;
      if (abs(t) > 10) {
        for (int j = w - 1; j >= 0; j--)
          cout << r[i][j];
        cout << "\n";
      } else {
        string s = r[i];
        while (s.back() == ' ')
          s.pop_back();
        if (s.length())
          cout << s << "\n";
      }
    }
  }
}