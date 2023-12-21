#include <bits/stdc++.h>

using namespace std;

int main() {
  int limit[5] = {2,4,8,10,16}, result[5] = {0}, last[5] = {0};
	string s;
  while (getline(cin, s)) {

    if (s == "^^^") {
      int sum = 0;
      for (int i = 0; i < 5; i++) {
        sum += result[i];
        result[i] = 0;
        last[i] = 0;
      }
      cout << sum << "\n";
    } else {

      for (char c: (s + " ")) {
        if (isalpha(c)) {
          c = tolower(c) - 'a' + 10;
        }
        if (isdigit(c)) {
          c -= '0';
        }
        for (int i = 0; i < 5; i++) {
          if (c < limit[i] && c >= 0) {
            if (!last[i]) {
              last[i] = 1;
              result[i]++;
            }
          } else {
            last[i] = 0;
          }
        }
      }
    }
  }
}