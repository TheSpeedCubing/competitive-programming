#include <bits/stdc++.h>


using namespace std;

size_t pos;
int f,radix[5] = {
  2,
  4,
  8,
  10,
  16
};

int main() {
  string s;
  
  while (1) {
    unsigned n[5];
    for (int i = 0; i < 5; i++) {
      if (!(cin >> s))
        exit(0);
      n[i] = stol(s, & pos, radix[i]);
    }

    if (f++)
      cout << "\n";

    cin.ignore();
    string buf;
    while (getline(cin, s)) {
      buf += s;
      if (s == "^^^") {
        for (int i = 0; i < 5; i++) {
          unsigned l = 0;
          int r = radix[i];

          for (char c: buf) {
            int v = isdigit(c) ? c - '0' : (isalpha(c) ? 10 + tolower(c) - 'a' : -1);
            if (v >= 0 && v < r) {
              l = (l * r + v) % n[i];
            }
          }
          string to;
          while (l) {
            to = (char)(l % r + (l % r > 9 ? 55 : 48)) + to;
            l /= r;
          }
          cout << (to == "" ? "0" : to) << "\n";
        }
        break;
      }
    }
  }
}