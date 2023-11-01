#include <iostream>

#include <string>

using namespace std;

int main() {
  long long a, b, c;
  while (cin >> a >> b >> c) {
    if (a % b) {
      string result = to_string(a / b) + ".";
      a %= b;
      int i = 1;
      while (c--) {
        a *= 10;
        result += to_string(a / b);
        a %= b;
        if (a == 0) {
          i = 0;
          break;
        }
      }
      if (i) {
        i = result.length();
        result[i - 1] += (to_string(a * 10 / b)[0] > '4');
        while (i--) {
          if (result[i] >= ':') {
            result[i] = '0';
            if (i) {
              result[result[i - 1] == '.' ? i-- - 2 : i - 1]++;
            } else {
              result = '1' + result;
            }
          }
        }
      }
      cout << result << "\n";
    } else
      cout << a / b << "\n";
  }
}