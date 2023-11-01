#include <iostream>

using namespace std;

int s[5];

int main() {
  int f;
  while (cin >> f >> s[0] >> s[1] >> s[2] >> s[3] >> s[4]) {
    int op[4] = {
      0
    };
    while (op[0] != 4) {
      int calc = s[0], t, i = 1;
      for (; i < 5; i++) {
        t = op[i - 1];
        calc = t == 0 ? calc + s[i] : (t == 1 ? calc - s[i] : (t == 2 ? calc * s[i] : (s[i] == 0 ? -2147483648 : calc / s[i])));
      }
      if (f == calc) {

        for (i = 0; i < 4; i++)
          cout << (op[i] == 0 ? "+" : (op[i] == 1 ? "-" : (op[i] == 2 ? "*" : "/")));
        cout << "\n";
        break;
      } else {
        op[3]++;
        i = 3;
        while (i--) {
          if (op[i + 1] == 4) {
            op[i + 1] = 0;
            op[i]++;
          }
        }
      }
    }
    if (op[0] == 4)
      printf("No way!\n");
  }
}